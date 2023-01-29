//==============================================
// Name: Smitkumar Kalpeshkumar Patel
// Student Number: 157308214
// Email: spatel556@myseneca.ca
// Section:NBB
// Workshop: w1p1       
// Date : May , 20th 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.  
//==============================================

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds {

	// Function Prototypes:
	void removeItem(int index);
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	void displayList();
	void removeBoughtItems();
	bool loadList();
	bool saveList();
	bool listIsEmpty();
	
}
#endif // !SDDS_SHOPPINGLIST_H
