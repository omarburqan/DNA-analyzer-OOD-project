#include <iostream>
#include "dna_seqList.h"

using namespace std;

class Observer
{
	public:
		Observer(std::vector<std::string>& temp):temp(temp){ }
		virtual ~Observer() {};
		virtual void find() = 0;
	protected:
		std::vector<std::string>& temp;
};

class Subject
{
	private:
		Observer* observer;
	public:
		Subject() :observer(NULL){         }
		void Execute()
		{
		    if (observer)
		        observer->find();
		}
		void RegisterObserver(Observer* observer)
		{
		    this->observer = observer;
		}
		void UnRegisterObserver(Observer* observer)
		{
		    this->observer = NULL;
		}
};
class ConcreateObserver : public Observer
{
	public:
		ConcreateObserver(std::vector<std::string>& temp):Observer(temp){}
		void find()
		{
		    std::string key1,key2;
			std::stringstream result;
			key1 = DnaSequenceList::getInstance()->getKey(temp.at(1));
			if (key1 == "wrong input")
				return;
			key2 = DnaSequenceList::getInstance()->getKey(temp.at(2));
			if (key2 == "wrong input"){
				DnaSequence temp_seq(temp.at(2));
				result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->findSub(&temp_seq);
			}
			else{
				result << ((DnaSequenceList::getInstance())->m_dnaData[key1])->findSub(((DnaSequenceList::getInstance())->m_dnaData[key2]));
			}
			std::cout <<  result.str() << std::endl;
		}
};
