#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include<vector>
#include<iostream>
#include"dna_seqList.h"

class Command 
{
	public:
	
		virtual std::string do_command(std::vector<std::string>& temp ) = 0;
		
	protected: // helping methods 
	
		unsigned int getHowMany(std::string name);
		std::string getKey(std::string );
		std::string createDna(std::string line,std::string seq_name);
};

class newCommand:public Command
{
	public:
		std::string do_command(std::vector<std::string>& temp );
};
class loadCommand:public Command
{
	public:
		std::string do_command(std::vector<std::string>& temp );
};
class dupCommand:public Command
{
	public:
		std::string do_command(std::vector<std::string>& temp );
};
class saveCommand:public Command
{
	public:
		std::string do_command(std::vector<std::string>& temp );
};

/**********************************/

class CommandFactory 
{
	public:
    	Command * getCommand(std::string& commandName);
};

/*********************************/


#endif //__COMMANDS_H__
