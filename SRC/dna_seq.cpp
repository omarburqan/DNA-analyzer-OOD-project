#include "dna_seq.h"
#include "fstream"

unsigned int DnaSequence::counter = 0;

// CTOR 
DnaSequence::DnaSequence(const char* data,std::string name){
	allocate_memory(data,strlen(data));
	m_id = ++counter;
	m_seqName = name;
}

DnaSequence::DnaSequence(const std::string& data,std::string name){
	allocate_memory(data.c_str(),data.length());
	m_id = ++counter;
	m_seqName = name;
}

DnaSequence::DnaSequence(const DnaSequence &other){ // copy CTOR 	
	char* temp = new char[other.m_length]; 
	for ( size_t i=0 ; i < other.m_length ; i++ ){ // copying other nuclear 
		temp[i] = other.m_nuclear[i]->get_char();
	}
	allocate_memory(temp,other.m_length);
	delete [] temp;
	
}

DnaSequence& DnaSequence::operator=(const DnaSequence& other){ // copy assingment 	
	if ( this == &other || other.m_length == 0 )
		return *this;
		
	freeNuclear();
	char* temp = new char[other.m_length]; 
	for ( size_t i=0 ; i < other.m_length ; i++ ){ // copying other nuclear 
		temp[i] = other.m_nuclear[i]->get_char();
	}
	allocate_memory(temp,other.m_length);
	delete [] temp;
	return *this;
}

DnaSequence& DnaSequence::operator=(const char* newData){  // copy assignment from c-string 
	freeNuclear();
	allocate_memory(newData,strlen(newData));
	return *this;
} 

DnaSequence& DnaSequence::operator=(const std::string& newData){ // copy assignment from std::string 
	return (*this = newData.c_str() ) ; 
}

std::ostream& operator<<(std::ostream &os, const DnaSequence &dna){ // left-shift operator to std::ostream
	os << "["<<dna.m_id <<"] " << dna.m_seqName << ": ";
	for ( size_t i=0 ; i < dna.m_length ; i++ ){
		os << dna.m_nuclear[i]->get_char();
	}
	os << std::endl;

	return os;
}

bool operator==(const DnaSequence &dna1,const DnaSequence &dna2){ // operator ==
	if (dna1.m_length != dna2.m_length)
		return false;
	for (size_t i = 0 ; i < dna1.m_length ; i++){
		if (dna1.m_nuclear[i] != dna2.m_nuclear[i])
			return false;
	}
	return true;
}

bool operator!=(const DnaSequence &dna1,const DnaSequence &dna2){ // operator !=
	return !(dna1 == dna2);
}
const char& DnaSequence::operator[](size_t index) const{ // operator []
	if (index > m_length)
		throw std::invalid_argument("bad index");
	return m_nuclear[index-1]->get_char();
} 
DnaSequence::~DnaSequence(){ 
	freeNuclear();
}




/**************************** PHASE 2 ********************************/

void DnaSequence::read_from(char* file_name){
	std::string line;
	std::ifstream myfile (file_name);
	if (myfile.is_open())
	{
		myfile >> line ;
		*this = line;
		myfile.close();
	}
	else
		throw "cant open file";
}
void DnaSequence::write_to(char* file_name){
	 std::ofstream myfile (file_name);
	  if (myfile.is_open())
	  {
	    myfile << *this << std::endl;
	    myfile.close();
	  }
	  else 
	  	throw "cant open file";
		
} 


DnaSequence DnaSequence::getSlice(size_t from, size_t to) const {

	if ( (from > to)  || from < 1  || to > m_length )
 		throw std::invalid_argument("index out of range ");
	char* temp = new char[(to-from)+1] ;
	size_t j =0;
	for ( size_t i= from ; i < to-1 ; i++ ){ 
		temp[j++]= m_nuclear[i]->get_char();
	}
	temp[j] = '\0';
	DnaSequence res(temp);
	delete [] temp;
	return (res);
}

DnaSequence** DnaSequence::getPairedStrand() const {
	std::string temp ;
	DnaSequence** result = new DnaSequence*[2];
	size_t i = 0;
	for ( ;i < m_length; ){ 
		temp += m_nuclear[i++]->pair();
	}
	result[0] = new DnaSequence(temp);
	temp="";
	i = m_length-1;
	while ( i != 0 ){ 
		temp += m_nuclear[i--]->pair();
	}
	temp+= m_nuclear[i]->pair();
	result[1] = new DnaSequence(temp);
	return (result);
}

long DnaSequence::findSub(DnaSequence* other)const{
	if ( other->m_length > m_length )
		return -1;
		
	size_t i;
    for (i = 0 ; i <= (m_length)-(other->m_length); ++i)
    {
    	size_t j;
        for ( j = 0; j < (other->m_length) ; ++j)
            if ( m_nuclear[i + j]->get_char() != other->m_nuclear[j]->get_char() )
                break;

        if (j == other->m_length)
            return (int)(i+1);
    }
    return -1;
}

size_t DnaSequence::countOccurrences(DnaSequence* other)const{
	return findAllSub(other).size();
}

std::list<int> DnaSequence::findAllSub(DnaSequence* other) const {
	if ( other->m_length > m_length )
		return std::list<int>();
 
    std::list<int> allSub;
    for (size_t i = 0; i <= (m_length)-(other->m_length); i++) 
    {   
        size_t j; 
        for (j = 0; j < (other->m_length); j++) 
            if ( m_nuclear[i + j]->get_char() != other->m_nuclear[j]->get_char() )
                break; 
   
        if (j == other->m_length)   
        { 
           allSub.push_back(int(i+1));
           j = 0;
        } 
    } 
    return allSub;
}

std::list<DnaSequence> DnaSequence::FindConsensusSequences()const { 
	// “Start Codon” is the sequence ATG. 
	// “End Codons” are TAG, TAA, TGA.
	DnaSequence startSeq("ATG");
	DnaSequence ds[] = {DnaSequence((char*)"TAG"),DnaSequence((char*)"TAA"),DnaSequence((char*)"TGA")};
	std::list<DnaSequence> result;
	
	long position = findSub(&startSeq);
	while ( position != -1 ){
		long min_end_pos = -1 ;
		for(long i =0 ; i<3;i++){	
			long end_pos = findSub(&ds[i]);
			if (min_end_pos == -1 || ( end_pos!=-1 && end_pos < min_end_pos))
				min_end_pos = end_pos;
		}
		if (min_end_pos != -1){
			result.push_back(getSlice(position,min_end_pos+3));
		    position = getSlice(position,sequenceLength()).findSub(&startSeq);
		
		}else
			break;	
	}
	return result;
}





// helping methods (private)
void DnaSequence::allocate_memory(const char* data,size_t length){
	m_nuclear = new NuclearTide*[length];
	for (size_t i=0 ; i< length ;i++){
		m_nuclear[i] = new NuclearTide(data[i]);
	}
	m_length = length;
}
void DnaSequence::freeNuclear(){
	for (size_t i=0 ; i < m_length ;i++){
		delete m_nuclear[i];
	}
	delete [] m_nuclear;
}


