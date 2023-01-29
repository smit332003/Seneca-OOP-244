//==============================================
// Name: Smitkumar Kalpeshkumar Patel
// Student Number: 157308214
// Email: spatel556@myseneca.ca
// Section:NBB
// Workshop: w1p1       
// Date : May , 20th 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.  
//==============================================

#ifndef SDDS_SHOPPINGRECH_H
#define SDDS_SHOPPINGRECH_H

namespace sdds {

    // Constant Value:
    const int MAX_TITLE_LENGTH = 50;

    // Structure:
    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    // Function Prototypes:
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif // !SDDS_SHOPPINGRECH_H
