#include <iostream>
#include "vector"
#include "dna_seqList.h"
#include "commands.h"
#include "factory.h"


using std::cout;
using std::endl;
using std::cin;

std::vector<std::string> split_data(const std::string &str)
{
	std::vector<std::string> cont;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
            cont.push_back(token);
    }
    return cont;
}
void printResult(std::string result){
	if(!result.empty())
		std::cout << result << std::endl;
}

int main(){
	Command *command;
	while(1){
		std::cout << "cmd >>> ";
		std::string input;
     	getline(cin, input);
		std::vector<std::string> keywords = split_data(input);
		if (keywords.front() == "quit"){
			break;
		}
		if (keywords.size() < 2){
			printResult("wrong input");			
			continue;
		}	
	    CommandFactory factory;
		command = factory.getCommand(keywords);
		if(command == 0){
			printResult("wrong command , no such command with that name");
		   	continue;
		}
		std::string result = command->do_command();
		printResult(result);
		delete command;
	}	

    /*std::map<std::string,DnaSequence*>::iterator it = DnaSequenceList::getInstance()->m_dnaData.begin();
	for ( ; it != DnaSequenceList::getInstance()->m_dnaData.end(); ++it){
		std::cout << "inside   " << *it->second << std::endl;
	}*/
	return 0;
}









