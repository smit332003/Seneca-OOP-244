/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <ostream>
#include "Account.h"

class SavingsAccount : public Account {

    public:
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;

    private:
        double interestRate = 0.0;
};

#endif