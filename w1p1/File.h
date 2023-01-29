//==============================================
// Name: Smitkumar Kalpeshkumar Patel
// Student Number: 157308214
// Email: spatel556@myseneca.ca
// Section:NBB
// Workshop: w1p1       
// Date : May , 20th 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.  
//==============================================

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds 
{

	// Function Prototypes:
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif // !SDDS_FILE_H
