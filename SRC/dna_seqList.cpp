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

unsigned int DnaSequenceList::getHowMany(std::string name){
	unsigned int counter = 0;
	for(std::map<std::string,DnaSequence*>::iterator it = m_dnaData.begin();
													 it != m_dnaData.end(); ++it) 
	{
		if(it->first.find(name,0) != std::string::npos){
			counter +=1;
		}
	}
	return counter;
}

std::string DnaSequenceList::createDna(std::string line,std::string seq_name){
	DnaSequence* res = new DnaSequence(line);	
	m_dnaData[seq_name] = res;
	std::stringstream id;
	id << ++m_dnaId;
	m_idToName[id.str()] = seq_name;
	std::stringstream result ;
	result << "[" << id.str() << "] " << seq_name << ": " << *(m_dnaData[seq_name]);
	return result.str();
}
std::string DnaSequenceList::getKey(std::string name){
	int isName;
	std::string key;
	if(name[0] == '#'){
		isName = 0;
	}
	else if (name[0] == '@'){
		isName = 1; 
	}
	else{
		return "wrong input";
	}
	size_t i = 1 ;
	while ( i < name.length() ){
		key += name[i++] ;
	}
	if(isName == 0 ) // in case of #id 
		key = m_idToName[key];
	return key;

}
