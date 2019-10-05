#include "dna_seqList.h"
#include "fstream"
#include <string.h>

unsigned int DnaSequenceList::default_name_counter = 0;


void DnaSequenceList::newSequence(const char* data,const char* seq_name){
	if (seq_name == NULL){
		std::stringstream ss;
		ss << "seq" << (++default_name_counter);
		seq_name = ss.str().c_str();
	}
	DnaSequence temp (data,seq_name);
	dna_list.push_back(temp);
	std::cout << temp << std::endl;
}

// cmd >>> load <file_name>  [@<sequence_name>]
void DnaSequenceList::loadSequence(const char* file_name,const char* seq_name) {
	if (seq_name == NULL) {
		seq_name = file_name;
	}
	
	size_t count = 0; 
	std::list<DnaSequence>::iterator it;
	for(it = dna_list.begin(); it != dna_list.end(); ++it){
		if ( it->m_seqName == seq_name ){
			count++;		
		}
	}
	if (count > 0 ) {
		std::stringstream ss;
		ss << seq_name << count;
		seq_name = ss.str().c_str();
	}
	
	std::string line;
	std::ifstream myfile (file_name);
	if (myfile.is_open())
	{
		myfile >> line ;
	}
	else
		throw "cant open file";
	DnaSequence temp(line,seq_name);
	dna_list.push_back(temp);
	std::cout << temp << std::endl;
}
		
void DnaSequenceList::dupSequence(size_t seqId,const char* seq_name) {
	if ( seq_name == NULL ) {
		size_t count = 0; 
		std::list<DnaSequence>::iterator it;
		for(it = dna_list.begin(); it != dna_list.end(); ++it){
			if ( it->m_id == seqId ){
				seq_name = it->m_seqName.c_str();		
			}
		}
		for(it = dna_list.begin(); it != dna_list.end(); ++it){
			if ( seq_name != NULL && it->m_seqName == seq_name ){
				count++;		
			}
		}
		if ( count > 0 ) {
			std::stringstream ss;
			ss << seq_name << "_" << count;
			seq_name = ss.str().c_str();
		}
	}
	std::list<DnaSequence>::iterator it;
	for(it = dna_list.begin(); it != dna_list.end(); ++it){
		if ( seq_name != NULL && it->m_id == seqId ){
			DnaSequence temp(" ",seq_name);
			temp = *it;
			dna_list.push_back(temp);
			std::cout << temp << std::endl;
			return;
		}
	}
	std::cout << "no seq with this id: "<< seqId  << std::endl;
}
		
void DnaSequenceList::SaveSequence(size_t seqId,char* file_name) {
	
}
