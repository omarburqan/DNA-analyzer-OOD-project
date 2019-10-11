#include "dna_seqList.h"

unsigned int DnaSequenceList::default_name_counter = 0;

unsigned int DnaSequenceList::m_dnaId = 0;

std::map<std::string,DnaSequence*> DnaSequenceList::m_dnaData;
		
std::map<std::string,std::string > DnaSequenceList::m_idToName;

/*
void DnaSequenceList::dupSequence(size_t seqId,const char* seq_name) {
	
	if (NULL == seq_name){
		int found = 0;
		std::list<DnaSequence>::iterator it;
		for(it = dna_list.begin(); it != dna_list.end(); ++it){
			if ( it->m_id == seqId ){
				found = 1;
				seq_name = it->m_seqName.c_str();
				break;
			}
		}
		if (found == 0){
			std::cout << "no sequence with this id: " << seqId << std::endl ;
			return; 
		}
	}
	
	size_t count = 0; 
	std::list<DnaSequence>::iterator it;
	for(it = dna_list.begin(); it != dna_list.end(); ++it){
		if ( it->m_seqName.find(seq_name,0) != std::string::npos ){
			count+=1;		
		}
	}
	if (count > 0 ) {
		std::stringstream ss;
		ss << seq_name << "_" << count;
		seq_name = ss.str().c_str();
	}
	int found = 0;
	for(it = dna_list.begin(); it != dna_list.end(); ++it){
		if ( it->m_id == seqId ){
			found = 1;
			DnaSequence temp(it->getSequence().c_str(),seq_name);
			dna_list.push_back(temp); 
			std::cout << temp << std::endl;
			break;
		}
	}
	if (found == 0){
			std::cout << "no sequence with this id: " << seqId << std::endl ;
			return; 
	}
}
		
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









