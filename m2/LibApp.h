/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Jul 22 2022          
   Assignment: 2   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#pragma once

#include "Menu.h"

namespace sdds
{
	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		bool confirm(const char* message);
		void load();
		void save();
		void search();

		void returnPub();

	public:
		void newPublication();
		void removePublication();
		void checkOutPub();

		LibApp();
		void run();
	};
}