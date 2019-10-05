#include <iostream>

#include "dna_seqList.h"

using std::cout;
using std::endl;
using std::cin;


int main(){
	//std::string input ;
	//cout << endl;
	//cout << endl;
	//cout << "please enter your command" << endl;
	//cout << endl;
	//getline(cin,input) ;
	//cout << input << endl;
	
	
	DnaSequenceList list;
	list.newSequence("ACGT",(char*)"omar");
	list.newSequence("ACGT");
	list.newSequence("ACGT",(char*)"ahamd");
	list.newSequence("ACGT");
	
	
	list.loadSequence((char*)"dna.txt");

	list.loadSequence((char*)"dna.txt");
	list.loadSequence((char*)"dna.txt",(char*)"montaser");
	
	list.dupSequence(22);
	list.dupSequence(22,(char*)"ibrahim");
	
	
	return 0;
}
