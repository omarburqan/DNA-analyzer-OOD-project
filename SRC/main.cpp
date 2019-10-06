#include <iostream>
#include "dna_seqList.h"

using std::cout;
using std::endl;
using std::cin;

void oldTester(){
	DnaSequenceList list;
	list.newSequence("ACGT",(char*)"omar");
	list.newSequence("ACGT");
	list.newSequence("ACGT",(char*)"ahamd");
	list.newSequence("ACGT");
	
	
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna",(char*)"montaser");
	
	
	list.saveSequence(10);
	list.saveSequence(4,(char*)"arar.rawdna");
	list.saveSequence(9);
	
	list.dupSequence(8);
	list.dupSequence(4,(char*)"unknown");
	list.dupSequence(12,(char*)"unknown");

}

int main(){
	std::string input ;
	cout << endl;
	cout << "please enter your command" << endl;
	cout << endl;
	getline(cin,input) ;
	cout << input << endl;
	
	

	
		
	return 0;
}









