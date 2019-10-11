#include "commands.h"
//===========================================================================

Command * CommandFactory::getCommand(std::string& commandName) {
    if(commandName == "new")
        return new newCommand();
    /*if (commandName == "load")
        return new loadCommand();
    if (commandName == "dup")
        return new dupCommand();
    if (commandName == "save")
        return new saveCommand();*/
    return 0;
}

//===========================================================================

void newCommand::do_command(std::vector<std::string> &temp) {
	std::string seq_name;
	if (temp.size() < 2){
		return;
	} 
    if (temp.size() == 2){
    	std::stringstream ss;
		ss << "$eqDefaultName" << ++DnaSequenceList::default_name_counter;
		seq_name = ss.str();
	}
	if (temp.size() == 3){
		seq_name = temp.at(2);

	}
	DnaSequence result(temp.at(1));	
	DnaSequenceList::m_dnaData[seq_name] = &result;
	std::stringstream id;
	id << ++DnaSequenceList::m_dnaId;
	DnaSequenceList::m_idToName[id.str()] = seq_name;
	std::cout << "[" << id.str() << "] " << seq_name << ": " << result;
}

//===========================================================================


