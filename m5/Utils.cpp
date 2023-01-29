 /*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: Aug 7 2022          
   Assignment: 5   
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "Utils.h"
using namespace std;
namespace sdds
{
    int getInteger()
    {
        int p;
        cin >> p;
        while (cin.fail() || cin.get() != '\n')
        {
            if (cin.fail())
                cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> p;
        }
        return p;
    }
    int getIntegerRange(int Minimum, int Maximum)
    {
        int i = getInteger();
        while (i < Minimum || i > Maximum)
        {
            cout << "Invalid Selection, try again: ";
            i = getInteger();
        }
        return i;
    }
}
