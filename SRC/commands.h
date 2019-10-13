#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include<vector>
#include<iostream>
#include"dna_seqList.h"

class Command 
{
	public:
		virtual std::string do_command() = 0;	
};

/****************Creation Commands******************/

class newCommand:public Command
{
	public:
		newCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};

class loadCommand:public Command
{
	public:
		loadCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};
class dupCommand:public Command
{
	public:
		dupCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};

/*****************Analysis Commands*****************/

class lenCommand:public Command
{
	public:
		lenCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};
class findCommand:public Command
{
	public:
		findCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};
class countCommand:public Command
{
	public:
		countCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};
class findallCommand:public Command
{
	public:
		findallCommand(std::vector<std::string>& temp);
		std::string do_command();
	private:
		std::vector<std::string>& temp;
};

/**********************************/

class CommandFactory 
{
	public:
    	Command * getCommand(std::vector<std::string>& temp);
};

/*********************************/


#endif //__COMMANDS_H__
