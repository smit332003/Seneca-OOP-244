/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

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