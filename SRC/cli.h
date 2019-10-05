#ifndef __CLI_H__
#define __CLI_H__

struct CommandLine {

		virtual void newSequence(const char* data,const char* seq_name = NULL) = 0 ;
		
		virtual void loadSequence(const char* file_name,const char* seq_name = NULL) = 0 ;
		
		virtual void dupSequence(size_t seqId,const char* seq_name = NULL) = 0 ; 
		
		virtual void SaveSequence(size_t seqId,char* file_name = NULL) = 0 ;
};


#endif //__CLI_H__
