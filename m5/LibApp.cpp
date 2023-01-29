 /*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 7 2022          
   Assignment: 5   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "LibApp.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <cstring>

#include "Book.h"
#include "PublicationSelector.h"

namespace sdds
{
	LibApp::LibApp(const char* filename): m_changed(false), m_filename{}, m_publications{}, m_numberOfPublications(), m_lastReferenceNumber(),
										m_mainMenu("Seneca Library Application"),
										m_exitMenu("Changes have been made to the data, what would you like to do?"),
										m_publicationType("Choose the type of publication:")
	{
		m_mainMenu << "Add New Publication" << "Remove Publication" <<
			"Checkout publication from library" << 
			"Return publication to library";
		m_exitMenu << "Save changes and exit" << 
			"Cancel and go back to the main menu";

		m_publicationType << "Book" << "Publication";
		if(filename)
			strcpy(m_filename, filename);
	}

	void LibApp::load()
	{
		std::cout << "Loading Data\n";
		std::ifstream file(m_filename);

		Publication* newPublication = nullptr;
		char pType;
		while(file >> pType)
		{
			if(pType == 'B')
				newPublication = new Book();
			else if(pType == 'P')
				newPublication = new Publication();
			
			file.ignore();
			file >> *newPublication;
			m_publications[m_numberOfPublications++] = newPublication;
			//m_publications[newPublication->getRef()] = newPublication;
			//m_lastReferenceNumber = newPublication->getRef();
			//m_numberOfPublications++;
		}
		m_lastReferenceNumber = m_publications[m_numberOfPublications - 1]->getRef();
	}

	void LibApp::save() const
	{
		std::cout << "Saving Data\n";

		std::ofstream file(m_filename, std::ios_base::out);

		for(int i = 0; i < SDDS_LIBRARY_CAPACITY; ++i) // i < m_numberOfPublications
		{
			if(m_publications[i] && m_publications[i]->getRef())
				file << *m_publications[i] << '\n';
		}
	}

	int LibApp::search(int mode) const
	{
		bool searchMode;
		PublicationSelector ps("Select one of the following found matches:");
		auto choice = m_publicationType.run(); // 1 - book | 2 - Publication
		char type;
		if(choice == 1)
			type = 'B';
		else if(choice == 2)
			type = 'P';
		else
		{
			std::cout << "Aborted!\n";
			return 0;
		}
		std::cout << "Publication Title: ";
		char title[256];
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin.getline(title, 256, '\n');
		for(int i = 0; i < SDDS_LIBRARY_CAPACITY; ++i) // i < m_numberOfPublications
		{
			if(!m_publications[i])
				continue;
			if(mode == 1)
				searchMode = true;
			else if(mode == 2)
				searchMode = m_publications[i]->onLoan();
			else if(mode == 3)
				searchMode = !m_publications[i]->onLoan();
			else
				return 0;
			if(m_publications[i]->type() == type && *m_publications[i] == title && searchMode)
				ps << *m_publications[i];

			if(m_publications[i]->getRef() == m_lastReferenceNumber)
				break;
		}
		if(ps)
		{
			ps.sort();
			const auto userSelection = ps.run();
			if(userSelection == 0)
			{
				std::cout << "Aborted!\n";
				return 0;
			}
			return userSelection;
		}
		std::cout << "No matches found!\n";
		return 0;
	}

	Publication* LibApp::getPub(int libRef) const
	{
		for(int i = 0; i < m_numberOfPublications; ++i)
		{
			if(m_publications[i]->getRef() == libRef)
				return m_publications[i];
		}
		return nullptr;
	}

	void LibApp::newPublication()
	{
		if(m_numberOfPublications == SDDS_LIBRARY_CAPACITY)
		{
			std::cout << "Library is at its maximum capacity!\n";
			return;
		}

		std::cout << "Adding new publication to the library\n";

		const unsigned choice = m_publicationType.run();
		char type;
		if(choice == 1)
			type = 'B';
		else if(choice == 2)
			type = 'P';
		else
		{
			std::cout << "Aborted!\n";
			return;
		}

		Publication* newPublication;
		if(type == 'B')
			newPublication = new Book();
		else
			newPublication = new Publication();
		std::cin.ignore(INT_MAX, '\n');
		newPublication->read(std::cin);

		if(std::cin.fail())
		{
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Aborted!\n";
			delete newPublication;
			return;
		}
		if(!confirm("Add this publication to the library?"))
		{
			std::cout << "Aborted!\n";
			delete newPublication;
			return;
		}

		if(*newPublication)
		{ 
			newPublication->setRef(++m_lastReferenceNumber);
			m_publications[m_numberOfPublications++] = newPublication;
			m_changed = true;
			std::cout << "Publication added\n";
		}
		else
		{
			std::cout << "Failed to add publication!\n";
		}
	}

	void LibApp::removePublication()
	{
		std::cout << "Removing publication from the library\n";
		int selectedPublicationRefNum = search();
		if(selectedPublicationRefNum == 0)
			return;

		Publication* SelectedPublication = getPub(selectedPublicationRefNum);
		
		std::cout << *SelectedPublication << '\n';

		if(!confirm("Remove this publication from the library?"))
			return;
		SelectedPublication->setRef(0);
		m_changed = true;
		std::cout << "Publication removed\n";
	}

	void LibApp::checkOutPub()
	{
		std::cout << "Checkout publication from the library\n";

		auto selectedPublicationRefNum = search(3);
		if(selectedPublicationRefNum == 0)
			return;

		Publication* SelectedPublication = getPub(selectedPublicationRefNum);

		std::cout << *SelectedPublication << '\n';
		
		if(!confirm("Check out publication?"))
			return;

		int number{};
		std::cout << "Enter Membership number: ";
		std::cin >> number;
		while(number < 10000 || number > 99999)
		{
			std::cout << "Invalid membership number, try again: ";
			std::cin.ignore(INT_MAX, '\n');
			std::cin >> number;
		}
		SelectedPublication->set(number);
		m_changed = true;
		std::cout << "Publication checked out\n";
	}

	void LibApp::returnPub()
	{
		std::cout << "Return publication to the library\n";
		auto selectedPublicationRefNum = search(2);
		if(selectedPublicationRefNum == 0)
			return;

		Publication* SelectedPublication = getPub(selectedPublicationRefNum);

		std::cout << *SelectedPublication << '\n';

		if(!confirm("Return Publication?"))
			return;
		Date currentDate;

		if(currentDate - SelectedPublication->checkoutDate() > SDDS_MAX_LOAN_DAYS)
		{
			int daysLate = currentDate - SelectedPublication->checkoutDate() - SDDS_MAX_LOAN_DAYS;
			double penalty = static_cast<double>(daysLate) * 0.5;
			std::cout << "Please pay $" << std::fixed << std::setprecision(2) << penalty << " penalty for being " << daysLate << " days late!\n";
		}
		SelectedPublication->set(0);
		m_changed = true;
		std::cout << "Publication returned\n";
	}

	bool LibApp::confirm(const char* message) const
	{
		Menu confirmationMenu(message);

		confirmationMenu << "Yes";
		const unsigned choice = confirmationMenu.run();
		return choice == 1;
	}

	void LibApp::run()
	{
		load();
		while(true)
		{
			unsigned choiceMain = m_mainMenu.run();
			if(choiceMain == 1)
				newPublication();
			else if(choiceMain == 2)
				removePublication();
			else if(choiceMain == 3)
				checkOutPub();
			else if(choiceMain == 4)
			{
				returnPub();
			}
			else
			{
				if(m_changed)
				{
					unsigned choiceExit = m_exitMenu.run();
					if(choiceExit == 1)
					{
						save();
						m_changed = false;
						break;
					}
					if(choiceExit == 0)
					{
						bool confirmed = confirm("This will discard all the changes are you sure?");
						if(confirmed)
						{
							m_changed = false;
							break;
						}
					}
					if(choiceExit == 2)
						std::cout << '\n';
				}
				else
				{
					m_changed = false;
					break;
				}
			}
			std::cout << '\n';
		}
		std::cout << "\n-------------------------------------------\n";
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
		if(m_filename)
		{
			std::ifstream file(m_filename);
			char line[256];
		    while (!file.fail() && !file.eof() )
		    {
		          file.getline(line, 256);
		          std::cout << line << std::endl;
		    }
		}
	}

	LibApp::~LibApp()
	{
		for(int i = 0; i < SDDS_LIBRARY_CAPACITY; ++i) // i < m_numberOfPublications
		{
			if(m_publications[i] && m_publications[i]->getRef() == m_lastReferenceNumber)
			{
				delete m_publications[i];
				break;
			}
			delete m_publications[i];
		}
	}
}
