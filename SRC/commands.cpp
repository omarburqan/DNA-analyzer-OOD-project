#include "commands.h"


//===========================================================================

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

//===========================================================================

newCommand::newCommand(std::vector<std::string>& temp):temp(temp){}

std::string newCommand::do_command() {
	std::stringstream seq_name;
    if (temp.size() == 2){
		seq_name << "SeqDefaultName" << ++DnaSequenceList::getInstance()->default_name_counter;
	}
	if (temp.size() == 3){
		if (temp.at(2)[0] != '@' || temp.at(2).length() == 1){
			return "wrong input";
		}
		std::stringstream parsed_name;
		size_t i = 1;
		while(i < temp.at(2).length() )
			parsed_name << temp.at(2)[i++];
		 
		unsigned int counter = DnaSequenceList::getInstance()->getHowMany(parsed_name.str());
		if ( counter > 0 )
			seq_name << parsed_name.str() << counter;
		else
			seq_name << parsed_name.str();
	}
	return DnaSequenceList::getInstance()->createDna(temp.at(1),seq_name.str());
}

//===========================================================================

loadCommand::loadCommand(std::vector<std::string>& temp):temp(temp){}

std::string loadCommand::do_command() {
	std::stringstream seq_name;
    if (temp.size() == 2){	
    	size_t i = 0;
    	while (temp.at(1)[i] != '.')
    		seq_name << temp.at(1)[i++];
	}
	if (temp.size() == 3){
		if (temp.at(2)[0] != '@' || temp.at(2).length() == 1){
			return "wrong input";
		}
		std::stringstream parsed_name;
		size_t i = 1;
		while(i < temp.at(2).length() )
			parsed_name << temp.at(2)[i++];
		temp.at(2) = parsed_name.str();
		seq_name << temp.at(2);
	}
	unsigned int counter = DnaSequenceList::getInstance()->getHowMany(seq_name.str());
	if ( counter > 0 )
		seq_name << counter;
	std::string line;
	std::ifstream myfile((char*)temp.at(1).c_str());
	if (myfile.is_open())
	{
		myfile >> line ;
	}
	else
		throw "cant open file";
	return DnaSequenceList::getInstance()->createDna(line,seq_name.str());
}

//===========================================================================

dupCommand::dupCommand(std::vector<std::string>& temp):temp(temp){}

std::string dupCommand::do_command() {
	std::stringstream seq_name;
	std::stringstream seq_data;
	std::string key;
	
	key = DnaSequenceList::getInstance()->getKey(temp.at(1));
	if (key == "wrong input" || key == "wrong input key doesnt not exist")
		return key;	
    if (temp.size() == 2){	// name was not provided 		
		seq_name << key;	
	}
	
	else if ( temp.size() == 3 ){ // name was provided 
		if (temp.at(2)[0] != '@' || temp.at(2).length() == 1){
			return "wrong input";
		}
		std::stringstream parsed_name;
		size_t i = 0;
		while(i < temp.at(2).length() )
			parsed_name << temp.at(2)[++i];
		temp.at(2) = parsed_name.str();
		seq_name << parsed_name;
	}
	unsigned int counter = DnaSequenceList::getInstance()->getHowMany(seq_name.str());
	if ( counter > 0 )
		seq_name << "_" << counter;
	for(std::map<std::string,DnaSequence*>::iterator it = DnaSequenceList::getInstance()->m_dnaData.begin();
														 it != DnaSequenceList::getInstance()->m_dnaData.end(); ++it) 
	{
		if(it->first == key){
			seq_data << *it->second ;
		}
	}
	return DnaSequenceList::getInstance()->createDna(seq_data.str(),seq_name.str());
}

//===========================================================================

lenCommand::lenCommand(std::vector<std::string>& temp):temp(temp){}

std::string lenCommand::do_command() {
	std::string key;
	std::stringstream result;
	key = DnaSequenceList::getInstance()->getKey(temp.at(1));
	if (key == "wrong input" || key == "wrong input key doesnt not exist" )
		return key;
	if (DnaSequenceList::getInstance()->m_dnaData.find( key ) != DnaSequenceList::getInstance()->m_dnaData.end() )
		result << (DnaSequenceList::getInstance()->m_dnaData[key])->sequenceLength() ;
	else
		return "wrong input";
	
	return result.str();
}

//===========================================================================

findCommand::findCommand(std::vector<std::string>& temp):temp(temp){}

std::string findCommand::do_command() {
    std::string key1,key2;
	std::stringstream result;
	key1 = DnaSequenceList::getInstance()->getKey(temp.at(1));
	if (key1 == "wrong input")
		return key1;
	key2 = DnaSequenceList::getInstance()->getKey(temp.at(2));
	if(key2 == "wrong input"){
		DnaSequence temp_seq(temp.at(2));
		result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->findSub(&temp_seq);
	}
	else if (key2 == "wrong input key doesnt not exist"){
		return key2;
	}
	else{
		if (DnaSequenceList::getInstance()->m_dnaData.find( key1 ) != DnaSequenceList::getInstance()->m_dnaData.end() && 
			DnaSequenceList::getInstance()->m_dnaData.find( key2 ) != DnaSequenceList::getInstance()->m_dnaData.end() )
			result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->findSub(((DnaSequenceList::getInstance())->m_dnaData[key2]));
		else
			return "wrong input key doesnt not exist";
	}
	return result.str();
}

//===========================================================================

countCommand::countCommand(std::vector<std::string>& temp):temp(temp){}

std::string countCommand::do_command() {
	std::string key1,key2;
	std::stringstream result;
	key1 = DnaSequenceList::getInstance()->getKey(temp.at(1));
	if (key1 == "wrong input")
		return key1;
	key2 = DnaSequenceList::getInstance()->getKey(temp.at(2));
	if(key2 == "wrong input"){
		DnaSequence temp_seq(temp.at(2));
		result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->countOccurrences(&temp_seq);
	}
	else if (key2 == "wrong input key doesnt not exist"){
		return key2;
	}
	else{
		if (DnaSequenceList::getInstance()->m_dnaData.find( key1 ) != DnaSequenceList::getInstance()->m_dnaData.end() && 
			DnaSequenceList::getInstance()->m_dnaData.find( key2 ) != DnaSequenceList::getInstance()->m_dnaData.end() )
			result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->countOccurrences(((DnaSequenceList::getInstance())->m_dnaData[key2]));
		else
			return "wrong input key doesnt not exist";
	}
	return result.str();
}

//===========================================================================

findallCommand::findallCommand(std::vector<std::string>& temp):temp(temp){}

std::string findallCommand::do_command() {
	std::string key1,key2;
	std::stringstream result;
	std::list<int> final_result;
	key1 = DnaSequenceList::getInstance()->getKey(temp.at(1));
	if (key1 == "wrong input")
		return key1;
	key2 = DnaSequenceList::getInstance()->getKey(temp.at(2));
	if(key2 == "wrong input"){
		DnaSequence temp_seq(temp.at(2));
		final_result = ((DnaSequenceList::getInstance())->m_dnaData[key1])->findAllSub(&temp_seq);
	}
	else if (key2 == "wrong input key doesnt not exist"){
		return key2;
	}
	else{
		if (DnaSequenceList::getInstance()->m_dnaData.find( key1 ) != DnaSequenceList::getInstance()->m_dnaData.end() && 
			DnaSequenceList::getInstance()->m_dnaData.find( key2 ) != DnaSequenceList::getInstance()->m_dnaData.end() )
			final_result = ((DnaSequenceList::getInstance())->m_dnaData[key1])->findAllSub(((DnaSequenceList::getInstance())->m_dnaData[key2]));
		else
			return "wrong input key doesnt not exist";
	}
	if (final_result.size()==0){
		return "-1";
	}
	std::list<int>::iterator it;
	for (it = final_result.begin(); it != final_result.end(); ++it){

		result << *it << " ";
	}
	
	return result.str();	
}

//===========================================================================















