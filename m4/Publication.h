/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 5 2022          
   Assignment: 4   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#pragma once

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds
{
	class Publication : public Streamable
	{
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;

	public:
		Publication();
		Publication(const Publication& other);
		Publication& operator=(const Publication& other);

		virtual void set(int member_id); 
		void setRef(int value); 
		void resetDate(); 

		virtual char type() const; 
		bool onLoan() const; 
		Date checkoutDate() const; 
		bool operator==(const char* title) const; 
		                                          
		operator const char*() const; 
		int getRef() const; 

		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& istr) override;
		bool conIO(std::ios& ios) const override;
		operator bool() const override;

		~Publication() override;
	};
}
