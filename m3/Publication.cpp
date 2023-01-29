/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 28 2022          
   Assignment: 3   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
  #include "Publication.h"

#include <iomanip>
#include <cstring>
#include <fstream>

namespace sdds
{
	Publication::Publication(): m_title(nullptr), m_shelfId(), m_membership(0), m_libRef(-1), m_date()
	{}

	Publication::Publication(const Publication& other): m_title(nullptr), m_shelfId(), m_membership(0), m_libRef(-1), m_date()
	{
		*this = other;
	}

	Publication& Publication::operator=(const Publication& other)
	{
		delete[] m_title;
		m_title = nullptr;
		if(other.m_title)
		{
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
		strcpy(m_shelfId, other.m_shelfId);

		m_membership = other.m_membership;
		m_libRef = other.m_libRef;
		m_date = other.m_date;

		return *this;
	}

	void Publication::set(const int member_id)
	{
		m_membership = member_id;
	}

	void Publication::setRef(const int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type() const
	{
		return 'P';
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::onLoan() const
	{
		return m_membership > 0;
	}

	bool Publication::operator==(const char* title) const
	{
		return std::strstr(m_title, title);
	}

	Publication::operator const char*() const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

	bool Publication::conIO(std::ios& ios) const
	{
		return &ios == &std::cin or &ios == &std::cout;
	}

	std::ostream& Publication::write(std::ostream& os) const
	{
		if(conIO(os))
		{
			char membership[6] = {" N/A "};
			if(onLoan())
				sprintf(membership, "%d", m_membership);
			os.setf(std::ios::left);
			os << "| " <<  m_shelfId << " |" << " " << std::setw(SDDS_TITLE_WIDTH) << 
				std::setfill('.') << m_title << " | " << 
				membership << " | " << m_date << " |";
			os.unsetf(std::ios::left);
			os << std::setfill(' ');
		}
		else
		{
			char membership[6] = {" N/A "};
			if(onLoan())
				sprintf(membership, "%d", m_membership);

			os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' <<
				m_title << '\t' << membership << '\t' << m_date;
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		delete[] m_title;
		m_title = nullptr;
		m_membership = 0;
		m_libRef = -1;
		resetDate();

		char title[255];
		char shelfId[SDDS_SHELF_ID_LEN + 1];
		int membership = 0;
		int libRef = -1;
		Date date;

		if(conIO(istr))
		{
			std::cout << "Shelf No: ";
			istr.getline(shelfId, 5);
			if(istr.fail() || istr.eof() || istr.gcount() != 5)
			{
				istr.setstate(std::istream::failbit);
			}
			std::cout << "Title: ";
			
			(istr >> std::ws).getline(title, 255);
			istr.sync();
			std::cout << "Date: ";
			istr >> date;
		}
		else
		{
			istr >> libRef;
			(istr >> std::ws).getline(shelfId, 5, '\t');
			(istr >> std::ws).getline(title, 255, '\t');
			istr.sync();
			istr >> membership;
			istr >> date;
			if(!istr)
				istr.ignore();
		}
		if(date.errCode())
			istr.setstate(std::istream::failbit);
		if(istr.good())
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}

	Publication::operator bool() const
	{
		return m_title && strlen(m_shelfId);
	}

	Publication::~Publication()
	{
		delete[] m_title;
	}
}
