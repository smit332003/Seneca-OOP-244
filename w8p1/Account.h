/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iomanip>
#include "iAccount.h"

class Account: public iAccount {

public:
    Account(double);
    bool credit(double);
    bool debit(double);
    iAccount* CreateAccount(const char* str, double balance);

protected:
    double Balance() const;

private:
    double balance = 0.0;
};

#endif