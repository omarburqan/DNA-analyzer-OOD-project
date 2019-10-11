#ifndef __DNA_SEQUENCE_LIST_H__
#define __DNA_SEQUENCE_LIST_H__

#include <iostream>
#include "dna_seq.h"
#include <map>


class DnaSequenceList {
	
	public:
		
		static unsigned int default_name_counter; 

		static unsigned int m_dnaId;	
		
		static std::map<std::string,DnaSequence*> m_dnaData;
		
    	static std::map<std::string,std::string > m_idToName;
    		
};


#endif /* __DNA_SEQUENCE_LIST_H__ */



