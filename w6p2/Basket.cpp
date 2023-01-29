/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 11 2022           
   Workshop: 6 Part- 2     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#include "Basket.h"

namespace sdds
{
	Basket::Basket()
	{
		m_fruit = nullptr;
		m_cnt = 0;
		m_price = 0.;
	}

	Basket::Basket(const Fruit* fruits, const int size, const double price)
	{
		if(fruits && size > 0 && price > 0)
		{
			m_cnt = size;
			m_price = price;

			m_fruit = new Fruit[m_cnt];
			for(int i = 0; i < m_cnt; ++i)
			{
				m_fruit[i] = fruits[i];
			}
		}
		else
		{
			m_fruit = nullptr;
			m_cnt = 0;
			m_price = 0.;
		}
	}

	Basket::Basket(const Basket& other)
	{
		m_fruit = nullptr;
		m_cnt = 0;
		m_price = 0.;
		*this = other;
	}


	Basket& Basket::operator=(const Basket& other)
	{
		delete[] m_fruit;
		m_fruit = nullptr;

		m_cnt = other.m_cnt;
		m_price = other.m_price;

		if(other)
		{
			m_fruit = new Fruit[m_cnt];
			for(int i = 0; i < m_cnt; ++i)
			{
				m_fruit[i] = other.m_fruit[i];
			}
		}

		return *this;
	}

	Basket::~Basket()
	{
		delete[] m_fruit;
	}

	void Basket::setPrice(double price)
	{ 
		m_price = price;
	}

	std::ostream& Basket::display(std::ostream& out) const
	{
		if(m_cnt == 0)
		{
			out << "The basket is empty!" << std::endl;
		}
		else
		{
			out << "Basket Content:" << std::endl;
			out << std::fixed;
			out << std::setprecision(2);
			for(int i = 0; i < m_cnt; ++i)
			{ 
				out << std::setw(10) << m_fruit[i].m_name << ": " << m_fruit[i].m_qty << "kg" << std::endl;
			}
			out << "Price: " << std::setprecision(2) << m_price << std::endl;
		}
		return out;
	}

	Basket::operator bool() const
	{
		return m_fruit != nullptr;
	}

	Basket& Basket::operator+=(Fruit fruit)
	{
		auto temp = new Fruit[m_cnt + 1];

		for(int i = 0; i < m_cnt; ++i)
		{
			temp[i] = m_fruit[i];
		}

		temp[m_cnt] = fruit;
		m_cnt++;
		delete[] m_fruit;

		m_fruit = temp;

		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const Basket& basket)
	{
		return basket.display(out);
	}
}
