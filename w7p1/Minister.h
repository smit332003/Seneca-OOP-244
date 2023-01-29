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

#include "MemberParliament.h"

namespace sdds
{
	class Minister : public MemberParliament
	{

	public:
		Minister(const char* Prlmnt_ID, unsigned int age, unsigned int Assumed_Office, const char* P_minister, const char* Dist);

		void changePM(const char* pm);
		void assumeOffice(double year);

		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

	private:
		char P_minister[50];
		double Assumed_Office;
	};

	std::ostream& operator<<(std::ostream&, sdds::Minister);
	std::istream& operator>>(std::istream&, sdds::Minister&);
}