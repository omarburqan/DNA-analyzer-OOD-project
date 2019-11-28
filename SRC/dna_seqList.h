#ifndef __DNA_SEQUENCE_LIST_H__
#define __DNA_SEQUENCE_LIST_H__

#include <iostream>
#include "dna_seq.h"
#include <map>

class DnaSequenceList {
	
	public:
    	
    	static DnaSequenceList* getInstance();
    	~DnaSequenceList(){delete[] obj;}
     	
     	unsigned int default_name_counter; 

		unsigned int m_dnaId;	
		
		std::map<std::string,DnaSequence*> m_dnaData;
		
    	std::map<std::string,std::string > m_idToName;
    	
        // helping methods 
	
		unsigned int getHowMany(std::string name);

		std::string createDna(std::string line,std::string seq_name);
		
		std::string getKey(std::string );
    	
	private:
	
		DnaSequenceList();
		
		static DnaSequenceList* obj;
			
};
#endif /* __DNA_SEQUENCE_LIST_H__ */
