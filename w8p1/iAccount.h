/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#ifndef IACCOUNT_H
#define IACCOUNT_H

#include<ostream>

//Interface iAccount
class iAccount {
    public:
        virtual bool credit(double) = 0; //adds a positive amount to the account balance
        virtual bool debit(double) = 0; //subtracts a positive amount from the account balance
        virtual void monthEnd() = 0; //applies month-end transactions to the account
        virtual void display(std::ostream&) const = 0; //inserts account information into an ostream object
        virtual ~iAccount(){} //empty virtual destructor
        iAccount* CreateAccount(const char* str, double balance);
};
namespace sdds {
    iAccount* CreateAccount(const char* str, double balance);
} //coded and is provided in the allocator module and will be used at final submission
#endif