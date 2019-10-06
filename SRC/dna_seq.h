#ifndef __DNA_SEQUENCE_H__
#define __DNA_SEQUENCE_H__

#include "nuclear.h"
#include <string.h>
#include <stdlib.h>
#include <sstream> 
#include <list>
#include "fstream"

class DnaSequence{

	public:
		
		// CTOR  c-string
		DnaSequence(const char * data,std::string name=NULL);

		// CTOR std::string 
		DnaSequence(const std::string&,std::string name=NULL);

		// Support construction and assignment from another DnaSequence.
		DnaSequence(const DnaSequence &); // copy CTOR 
		DnaSequence& operator =(const DnaSequence&); // copy assingment 	
		
		// Support assignment from c-string and std::string.
		DnaSequence& operator =(const char*); 
		DnaSequence& operator =(const std::string&); 
		
		// Support streaming out (left-shift operator to std::ostream)
		friend std::ostream& operator<<(std::ostream &os, const DnaSequence  &);
		
		// Support operator==(), operator!=()
		friend bool operator==(const DnaSequence &,const DnaSequence &);
		friend bool operator!=(const DnaSequence &,const DnaSequence &);
		
		// Support operator[] to refer the nucleotide in the relevant index
		const char& operator[] (size_t) const;  
		
		// Provide sequence length
		size_t sequenceLength() const;
	
		~DnaSequence();
		
		/*****-***** phase 2 *****-*****/
		
		void read_from(char* );
		
		void write_to(char* ); 
		
		DnaSequence getSlice(size_t , size_t ) const ;
	    
		DnaSequence** getPairedStrand() const ;
		
		long findSub(DnaSequence*) const ;
		
		size_t countOccurrences(DnaSequence*) const ; 
		
		std::list<int> findAllSub(DnaSequence*) const ;
		
		std::list<DnaSequence> FindConsensusSequences() const;
		
		std::string m_seqName;
		
		unsigned int m_id;
		
	private:
	
		NuclearTide** m_nuclear;
		
		size_t m_length;
		
		static unsigned int counter ;
		
		// helping methods
		void allocate_memory(const char* data,size_t length);
		
		void freeNuclear();
};


inline size_t DnaSequence::sequenceLength() const{
	return m_length;
}

#endif /* __DNA_SEQUENCE_H__ */



