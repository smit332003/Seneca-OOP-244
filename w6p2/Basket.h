/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 11 2022           
   Workshop: 6 Part- 2     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_

#include <iostream>
#include <iomanip>

namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket
	{
	private:
		Fruit* m_fruit; // a dynamically allocated array of objects of type `Fruit`
		int m_cnt;      // the size of the `m_fruits` array.
		double m_price; // the price of the basket

	public:
		Basket();
		Basket(const Fruit* fruits, const int size, const double price);
		Basket(const Basket& other);
		Basket& operator=(const Basket& other);
		~Basket();

		void setPrice(double price);
		std::ostream& display(std::ostream& out) const; // to get the size of the m_fruit array
		operator bool() const;
		Basket& operator+=(Fruit fruit);

		friend std::ostream& operator<<(std::ostream& out, const Basket& basket);
	};
}

#endif
