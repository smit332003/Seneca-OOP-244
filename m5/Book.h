 /*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 7 2022          
   Assignment: 5   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#pragma once

#include "Publication.h"

namespace sdds
{
	class Book : public Publication
	{
		char* m_author_name;

	public:
		Book();

		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book() override;

		char type() const override;
		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& istr) override;
		void set(int member_id) override;
		operator bool() const override;
	};
}

