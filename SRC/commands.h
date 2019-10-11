#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include<vector>
#include<iostream>
#include"dna_seqList.h"

class Command 
{
	public:
		virtual void do_command(std::vector<std::string>& temp ) = 0;
};

class newCommand:public Command
{
	public:
		void do_command(std::vector<std::string>& temp );
};
class loadCommand:public Command
{
	public:
		void do_command(std::vector<std::string>& temp );
};
class dupCommand:public Command
{
	public:
		void do_command(std::vector<std::string>& temp );
};
class saveCommand:public Command
{
	public:
		void do_command(std::vector<std::string>& temp );
};

/**********************************/

class CommandFactory {
public:
    Command * getCommand(std::string& commandName);
};

/*********************************/


#endif //__COMMANDS_H__
