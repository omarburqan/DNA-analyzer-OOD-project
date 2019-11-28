#include "factory.h"

Command* CommandFactory::getCommand(std::vector<std::string>& commandName) {
    if (commandName.at(0) == "new"){
        return new newCommand(commandName);
    }
    if (commandName.at(0) == "load"){
        return new loadCommand(commandName);
    }
    if (commandName.at(0) == "dup"){
        return new dupCommand(commandName);
    }
    if (commandName.at(0) == "len"){
    	return new lenCommand(commandName);
	}
	if (commandName.at(0) == "find"){
    	return new findCommand(commandName);
	}
	if (commandName.at(0) == "count"){
    	return new countCommand(commandName);
	}
	if (commandName.at(0) == "findall"){
    	return new findallCommand(commandName);
	}
    	
    return 0;
}
