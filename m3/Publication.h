/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 28 2022          
   Assignment: 3   
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

		virtual void set(int member_id); // Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value); // Sets the **libRef** attribute value.
		void resetDate(); // Sets the date to the current date of the system.

		virtual char type() const; // Returns the character 'P' to identify this object as a "Publication object".
		bool onLoan() const; // Returns true if the publication is checkout (membership is non-zero).
		Date checkoutDate() const; // Returns the date attribute.
		bool operator==(const char* title) const; // Returns true if the argument title appears anywhere in the title of the 
		                                          // publication. Otherwise, it returns false.
		operator const char*() const; // Returns the title attribute.
		int getRef() const; //Returns the libRef attribute.

		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& istr) override;
		bool conIO(std::ios& ios) const override;
		operator bool() const override;

		~Publication() override;
	};
}
