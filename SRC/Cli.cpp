#include <iostream>
#include "dna_seqList.h"
#include "commands.h"
#include "vector"

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
	std::cout << result << std::endl;
}

int main(){
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
		Command* command = factory.getCommand(keywords);
		if(command == 0){
			printResult("wrong input");
		    return -1;
		}
	    printResult(command->do_command());
	}	
	return 0;
}









