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
#include "Lib.h"
#include "Menu.h"

namespace sdds
{
	class LibApp
	{
		bool m_changed;
		char m_filename[256]; // Publication data file name
		Publication* m_publications[SDDS_LIBRARY_CAPACITY]; // all the records of the publication data file when the LibApp is instantiated (PPA)
		int m_numberOfPublications; // the number of Publications loaded into the 'm_publications' (NOLP)
		int m_lastReferenceNumber; // the last library reference number read from the data file (LLRN)
		Menu m_mainMenu;
		Menu m_exitMenu;
		Menu m_publicationType; // Menu for selection publication type

		void load();
		void save() const;
		int search(int mode = 1) const; // mode = 1: search all
			// mode = 2: search checkout items
			// mode = 3: search available items
		Publication* getPub(int libRef) const;

		bool confirm(const char* message) const;
		void returnPub();

	public:
		LibApp(const char* filename);

		void newPublication();
		void removePublication();
		void checkOutPub();

		void run();
		~LibApp();
	};
}
