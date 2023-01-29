 /*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 7 2022          
   Assignment: 5   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "Streamable.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& out, const Streamable& streamable)
	{
		if(streamable)
		{
			streamable.write(out);
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, Streamable& streamable)
	{
		streamable.read(in);
		return in;
	}
}
