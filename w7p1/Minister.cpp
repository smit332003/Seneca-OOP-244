/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 15 2022          
   Workshop: 7 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/


#include "Minister.h"
#include <cstring>

namespace sdds
{
	Minister::Minister(const char* Prlmnt_ID, unsigned int age, unsigned int Assumed_Office, const char* P_minister, const char* Dist)
		:MemberParliament(Prlmnt_ID, age, Dist)
	{
		std::memcpy(this->P_minister, P_minister, sizeof(this->P_minister));
		this->Assumed_Office = Assumed_Office;
	}

	void Minister::changePM(const char* pm)
	{
		std::memcpy(this->P_minister, pm, sizeof(this->P_minister));
	}

	void Minister::assumeOffice(double year)
	{
		this->Assumed_Office = year;
	}

	std::ostream& Minister::write(std::ostream& os)
	{
		MemberParliament::write(os);
		os << " | " << P_minister << "/" << Assumed_Office << "";
		return os;
	}

	std::istream& Minister::read(std::istream& in)
	{
		MemberParliament::read(in);
		std::cout << "Reports TO: ";
		in >> P_minister;
		std::cout << "Year Assumed Office: ";
		in >> Assumed_Office;
		return in;
	}

	std::ostream& operator<<(std::ostream& stream, Minister minister)
	{
		return minister.write(stream);
	}

	std::istream& operator>>(std::istream& stream, Minister& minister)
	{
		return minister.read(stream);
	}
}