#include "commands.h"

unsigned int Command::getHowMany(std::string name){
	unsigned int counter = 0;
	for(std::map<std::string,DnaSequence*>::iterator it = DnaSequenceList::m_dnaData.begin();
													 it != DnaSequenceList::m_dnaData.end(); ++it) 
	{
		if(it->first.find(name,0) != std::string::npos){
			counter +=1;
		}
	}
	return counter;
}
std::string Command::createDna(std::string line,std::string seq_name){
	DnaSequence res(line);	
	DnaSequenceList::m_dnaData[seq_name] = &res;
	std::stringstream id;
	id << ++DnaSequenceList::m_dnaId;
	DnaSequenceList::m_idToName[id.str()] = seq_name;
	std::stringstream result ;
	result << "[" << id.str() << "] " << seq_name << ": " << res;
	return result.str();
}

//===========================================================================

Command * CommandFactory::getCommand(std::string& commandName) {
    if(commandName == "new")
        return new newCommand();
    if (commandName == "load")
        return new loadCommand();
    if (commandName == "dup")
        return new dupCommand();
    /*if (commandName == "save")
        return new saveCommand();*/
    return 0;
}

//===========================================================================

std::string newCommand::do_command(std::vector<std::string> &temp) {
	std::stringstream seq_name;
    if (temp.size() == 2){
		seq_name << "$eqDefaultName" << ++DnaSequenceList::default_name_counter;
	}
	if (temp.size() == 3){
		unsigned int counter = getHowMany(temp.at(2));
		if ( counter > 0 )
			seq_name << temp.at(2) << counter;
		else
			seq_name << temp.at(2);
	}
	return createDna(temp.at(1),seq_name.str());
}

//===========================================================================

std::string loadCommand::do_command(std::vector<std::string> &temp) {
	std::stringstream seq_name;
    if (temp.size() == 2){	
    	seq_name << temp.at(1);
	}
	if (temp.size() == 3){
		unsigned int counter = getHowMany(temp.at(2));
		if ( counter > 0 )
			seq_name << temp.at(2) << counter;
		else
			seq_name << temp.at(2);
	}
	std::string line;
	std::ifstream myfile((char*)temp.at(1).c_str());
	if (myfile.is_open())
	{
		myfile >> line ;
	}
	else
		throw "cant open file";
	return createDna(line,seq_name.str());
}

//===========================================================================

std::string dupCommand::do_command(std::vector<std::string> &temp) {
	std::stringstream seq_name;
    if (temp.size() == 2){	
    	if(){
    			
    	}
    	else{
    	
    	}
	}
	if (temp.size() == 3){
		unsigned int counter = getHowMany(temp.at(2));
		if ( counter > 0 )
			seq_name << temp.at(2) << counter;
		else
			seq_name << temp.at(2);
	}
	
	return seq_name.str();
}

//===========================================================================
