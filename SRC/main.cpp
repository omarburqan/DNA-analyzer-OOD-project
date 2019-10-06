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
	
	
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna");
	list.loadSequence((char*)"dna.rawdna",(char*)"montaser");
	
	/*std::list<DnaSequence>::iterator it;
	for(it = list.dna_list.begin(); it != list.dna_list.end(); ++it){
		cout << *it  << endl;
	}*/	
	list.saveSequence(4);
	
	return 0;
}
