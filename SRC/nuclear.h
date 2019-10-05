#ifndef __NUCLEAR_TIDE_H__
#define __NUCLEAR_TIDE_H__

#include <iostream>
#include <list>


struct BadInput : public std::exception
{
	const char * what () const throw ()
    {
    	return  "bad -- index";
    }
};

class NuclearTide{

	public:
		NuclearTide(const char& sub);
		~NuclearTide();
		const char& get_char() const;
		const char pair() const;
		
	private:
		char m_nuc;
		static const std::string consist;
		bool check_data_validation(const char& dna) const;
		
};


inline NuclearTide::NuclearTide(const char& sub):m_nuc(sub){
	if ( !check_data_validation(sub) )
		throw BadInput();
}

inline NuclearTide::~NuclearTide(){ }

inline const char& NuclearTide::get_char() const { return m_nuc; }

// helping method
inline bool NuclearTide::check_data_validation(const char& dna) const {
	for (size_t i = 0 ; i<consist.length() ; i++)
	{
		if( dna == consist[i] )
		{
			return true;
		}
	}
	return false;
}
inline const char NuclearTide::pair() const
{
    char ch;
    if (m_nuc == 'A')
        ch = 'T';
    else if (m_nuc =='T')
    	ch = 'A';
	else if (m_nuc == 'C')
		ch = 'G';
	else 
		ch = 'C';
    return ch;
}

#endif // __NUCLEAR_TIDE_H__
