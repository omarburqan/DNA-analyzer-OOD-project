#ifndef __DNA_SEQUENCE_LIST_H__
#define __DNA_SEQUENCE_LIST_H__

#include <iostream>
#include "cli.h"
#include "dna_seq.h"
#include <sstream> 

class DnaSequenceList {
	
	public:
		
		void newSequence(const char* data, const char* seq_name = NULL) ;
		
		void loadSequence(const char* file_name,const char* seq_name = NULL) ;
		
		void dupSequence(size_t seqId,const char* seq_name = NULL) ; 
		
		void SaveSequence(size_t seqId,char* file_name = NULL) ;
		
	
		std::list<DnaSequence> dna_list ;
		static unsigned int default_name_counter; 
		
};


#endif /* __DNA_SEQUENCE_LIST_H__ */



