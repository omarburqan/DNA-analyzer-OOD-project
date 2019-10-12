#include "commands.h"

//===========================================================================

unsigned int Command::getHowMany(std::string name){
	unsigned int counter = 0;
	for(std::map<std::string,DnaSequence*>::iterator it = DnaSequenceList::getInstance()->m_dnaData.begin();
													 it != DnaSequenceList::getInstance()->m_dnaData.end(); ++it) 
	{
		if(it->first.find(name,0) != std::string::npos){
			counter +=1;
		}
	}
	return counter;
}

std::string Command::createDna(std::string line,std::string seq_name){
	DnaSequence res(line);	
	DnaSequenceList::getInstance()->m_dnaData[seq_name] = &res;
	std::stringstream id;
	id << ++DnaSequenceList::getInstance()->m_dnaId;
	DnaSequenceList::getInstance()->m_idToName[id.str()] = seq_name;
	std::stringstream result ;
	result << "[" << id.str() << "] " << seq_name << ": " << res;
	return result.str();
}
std::string Command::getKey(std::string name){
	int isName;
	std::string key;
	if(name[0] == '#'){
		isName = 0;
	}
	else if (name[0] == '@'){
		isName = 1; 
	}
	else{
		return "wrong input";
	}
	size_t i = 1 ;
	while ( i < name.length() ){
		key += name[i++] ;
	}
	if(isName == 0) // in case of #id 
		key = DnaSequenceList::getInstance()->m_idToName[key];
	return key;

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
		seq_name << "SeqDefaultName" << ++DnaSequenceList::getInstance()->default_name_counter;
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
	std::stringstream seq_data;
	std::string key;
	
	key = getKey(temp.at(1));
	if (key == "wrong input")
		return "wrong input";	
    if (temp.size() == 2){	// name was not provided 		
    	unsigned int counter = getHowMany(key);
		if ( counter > 0 )
			seq_name << key << "_" << counter;
		else
			seq_name << key;	
	}
	
	else if ( temp.size() == 3 ){ // name was provided 
		unsigned int counter = getHowMany(temp.at(2));
		if ( counter > 0 )
			seq_name << temp.at(2) << "_" << counter;
		else
			seq_name << temp.at(2);
	}
	
	for(std::map<std::string,DnaSequence*>::iterator it = DnaSequenceList::getInstance()->m_dnaData.begin();
														 it != DnaSequenceList::getInstance()->m_dnaData.end(); ++it) 
	{
		if(it->first == key){
			seq_data << it->second ;
		}
	}
	return createDna(seq_data.str(),seq_name.str());
}

//===========================================================================
