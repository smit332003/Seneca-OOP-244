/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 15 2022          
   Workshop: 7 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#include "MemberParliament.h"
#include <cstring>

namespace sdds
{
	MemberParliament::MemberParliament(const char* Prlmt_ID, unsigned int Age, const char* district)
	{
		std::memcpy(this->Prlmt_ID, Prlmt_ID, sizeof(this->Prlmt_ID));
		std::memcpy(this->district, "Unassigned", sizeof(this->district));
		if (strcmp(district, "Unassigned") != 0)
			NewDistrict(district);

		this->Age = Age;
	}

	void MemberParliament::NewDistrict(const char* district)
	{
		std::cout << "|";
		std::cout.width(8);
		std::cout << std::right << Prlmt_ID;
		std::cout << "| |";
		std::cout.width(20);
		std::cout << std::right << this->district;
		std::cout << " ---> ";
		std::cout.width(23);
		std::cout << std::left << district << "|" << std::endl;

		std::memcpy(this->district, district, sizeof(this->district));
	}

	std::ostream& MemberParliament::write(std::ostream& os)
	{
		os << "| " << Prlmt_ID << " | " << Age << " | " << district;
		return os;
	}

	std::istream& MemberParliament::read(std::istream& in)
	{
		std::cout << "Age: ";
		in >> Age;
		std::cout << "Id: ";
		in >> Prlmt_ID;
		std::cout << "District: ";
		in >> district;
		return in;
	}

	std::ostream& operator<<(std::ostream& stream, sdds::MemberParliament member)
	{
		return member.write(stream);
	}

	std::istream& operator>>(std::istream& stream, sdds::MemberParliament& member)
	{
		return member.read(stream);
	}
}