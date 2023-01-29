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
#include <iostream>

namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& ios) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() = default;
		friend std::ostream& operator<<(std::ostream& out, const Streamable& streamable);
		friend std::istream& operator>>(std::istream& in, Streamable& streamable);
	};
}
