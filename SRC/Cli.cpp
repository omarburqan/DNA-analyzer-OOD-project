#include <iostream>
#include "dna_seqList.h"
#include "commands.h"
#include "vector"

using std::cout;
using std::endl;
using std::cin;

std::vector<std::string>* split_data(const std::string &str, char delim = ' ')
{
	std::vector<std::string>* cont = new std::vector<std::string>();
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
            cont->push_back(token);
    }
    return cont;
}

int main(){

 	//while(1){
		std::cout << "cmd >>> ";
		std::string input;
     	getline(cin, input);
		std::vector<std::string> *keywords = split_data(input, ' ');
	    CommandFactory factory;
		Command * command = factory.getCommand(keywords->front());
		if(command != 0){
		    command->do_command(*keywords);
		}
		keywords->clear();
		delete keywords;
    //}

	
		
	return 0;
}









