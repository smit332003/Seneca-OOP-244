/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 15 2022          
   Workshop: 7 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#pragma once

#include <iostream>
#include <string>

namespace sdds
{
	class MemberParliament
	{
	public:
		MemberParliament(const char* Prlmt_ID, unsigned int Age, const char* district = "Unassigned");
		void NewDistrict(const char* district);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

	protected:

		char Prlmt_ID[32];
		char district[64];
		unsigned int Age;
	};

	std::ostream& operator<<(std::ostream&, sdds::MemberParliament);
	std::istream& operator>>(std::istream&, sdds::MemberParliament&);
}