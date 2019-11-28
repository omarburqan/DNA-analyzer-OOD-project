#ifndef __FACTORY_H__
#define __FACTORY_H__

#include<vector>
#include"commands.h"



class CommandFactory 
{
	public:
    	Command * getCommand(std::vector<std::string>& commandName);
};




#endif //__FACTORY_H__
