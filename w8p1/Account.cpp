
/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "Account.h"

/* 
constructor receives either a double holding the initial account balance or nothing. 
If the amount received is not positive-valued or no amount is received, this function initializes the current balance to 0.0. 
If the amount received is positive-valued, this function initializes the current account balance to the received amount.
*/
Account::Account(double initialBalance) { 
    if (initialBalance > 0.0)
        balance = initialBalance;
    else
        balance = 0.0;
}


// Balance() returns the current balance of the account.
double Account::Balance() const {
    return balance;
}

/*
receives an amount to be credited (added) to the account balance and returns the success of the transaction. 
If the amount received is positive-valued, the transaction succeeds and this function adds the amount received to the current balance. 
If the amount is not positive-valued, the transaction fails and this function does not add the amount received.
*/
bool Account::credit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

/*
receives an amount to be debited (subtracted) from the account balance and returns the success of the transaction. 
If the amount received is positive-valued, the transaction succeeds and this function subtracts the amount received from the current balance. 
If the amount is not positive-valued, the transaction fails and this function does not subtract the amount received.
*/
bool Account::debit(double amount) {
    if (amount > 0) {
        balance -= amount;
        return true;
    }
    return false;
}