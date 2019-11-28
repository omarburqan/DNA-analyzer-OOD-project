#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include<vector>
#include<iostream>
#include"dna_seqList.h"




class Command 
{
	public:
		virtual std::string do_command() = 0;
		virtual ~Command();
};
/***************Abstract class*********************/

class AbstractCommand:public Command
{
	public:
		AbstractCommand(std::vector<std::string>& commandLine);
	protected:
		std::vector<std::string>& commandLine;
};

/****************Creation Commands******************/

class newCommand:public AbstractCommand
{
	public:
		newCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	
};

class loadCommand:public AbstractCommand
{
	public:
		loadCommand(std::vector<std::string>& commandLine);
		std::string do_command();

};

class dupCommand:public AbstractCommand
{
	public:
		dupCommand(std::vector<std::string>& commandLine);
		std::string do_command();
};

/*****************Analysis Commands*****************/

class lenCommand:public AbstractCommand
{
	public:
		lenCommand(std::vector<std::string>& commandLine);
		std::string do_command();
};

class findCommand:public AbstractCommand
{
	public:
		findCommand(std::vector<std::string>& commandLine);
		std::string do_command();
};

class countCommand:public AbstractCommand
{
	public:
		countCommand(std::vector<std::string>& commandLine);
		std::string do_command();
};

class findallCommand:public AbstractCommand
{
	public:
		findallCommand(std::vector<std::string>& commandLine);
		std::string do_command();
};

/**********************************/




#endif //__COMMANDS_H__
