 /*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 7 2022          
   Assignment: 5   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "Book.h"
#include "Lib.h"
#include <iomanip>
#include <cstring>

namespace sdds
{
	Book::Book(): m_author_name(nullptr)
	{}

	Book::Book(const Book& book): Publication(book), m_author_name(nullptr)
	{
		*this = book;
	}

	Book& Book::operator=(const Book& book)
	{
		delete[] m_author_name;
		m_author_name = nullptr;
		if(book.m_author_name)
		{
			m_author_name = new char[strlen(book.m_author_name) + 1];
			strcpy(m_author_name, book.m_author_name);
		}
		Publication::operator=(book);

		return *this;
	}

	Book::~Book()
	{
		delete[] m_author_name;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if(conIO(os))
		{
			os << " ";
			if(strlen(m_author_name) > SDDS_AUTHOR_WIDTH)
			{
				for(int i = 0; i < SDDS_AUTHOR_WIDTH; ++i)
					os << m_author_name[i];
			}
			else
			{
				os.setf(std::ios::left);
				os << std::setw(SDDS_AUTHOR_WIDTH) << m_author_name;
				os.unsetf(std::ios::left);
			}
			os << " |";
		}
		else
		{
			os << '\t' << m_author_name;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr)
	{
		char author_name[256];

		Publication::read(istr);
		delete[] m_author_name;

		if(conIO(istr))
		{
			istr.ignore(1, '\n');
			std::cout << "Author: ";
			istr.get(author_name, 256, '\n');
		}
		else
		{
			istr.ignore(1, '\t');
			istr.get(author_name, 256, '\n');
		}
		if(!istr.fail())
		{
			auto length = strlen(author_name);
			//m_author_name = new char[length + 1];
			//strncpy(m_author_name, author_name, length);
			//m_author_name[length] = '\0';
			m_author_name = new char[length+1];
			strcpy(m_author_name, author_name);
		}

		return istr;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const
	{
		return m_author_name && strlen(m_author_name) > 0 && Publication::operator bool();
	}

}
