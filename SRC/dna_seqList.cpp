#include "dna_seqList.h"

DnaSequenceList* DnaSequenceList::obj = NULL;

DnaSequenceList::DnaSequenceList(){ 
	default_name_counter = 0 ;
	m_dnaId = 0 ;
}

DnaSequenceList* DnaSequenceList::getInstance(){ 
	if ( !obj ) 
	    obj = new DnaSequenceList(); 
    return obj; 
}


/*		
void DnaSequenceList::saveSequence(size_t seqId,char* file_name) {
	std::list<DnaSequence>::iterator it = dna_list.begin();
	int found = 0 ;
	for(it = dna_list.begin(); it != dna_list.end(); ++it){
		if ( it->m_id == seqId ){
			found = 1;
			break;
		}
	}
	if (found == 0){
		std::cout << "no sequence with this id: " << seqId << std::endl ;
		return; 
	}
	
	if (file_name == NULL){
		std::stringstream ss;
		ss << it->m_seqName << ".rawdna";
		file_name = (char*)ss.str().c_str();
	}
		
	std::ofstream myfile(file_name);
	if (myfile.is_open())
	{
		myfile << *it;
		myfile << std::endl;
		myfile.close();
	}
	else 
		throw "cant open file";
	std::cout << "sequence with this id: " << seqId << " was written successfuly" << std::endl ;
}
*/









