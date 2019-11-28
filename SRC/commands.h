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

/****************Creation Commands******************/

class newCommand:public Command
{
	public:
		newCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

class loadCommand:public Command
{
	public:
		loadCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

class dupCommand:public Command
{
	public:
		dupCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

/*****************Analysis Commands*****************/

class lenCommand:public Command
{
	public:
		lenCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

class findCommand:public Command
{
	public:
		findCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

class countCommand:public Command
{
	public:
		countCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

class findallCommand:public Command
{
	public:
		findallCommand(std::vector<std::string>& commandLine);
		std::string do_command();
	private:
		std::vector<std::string>& commandLine;
};

/**********************************/




#endif //__COMMANDS_H__
