/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
#include "ChequingAccount.h"

/*
constructor receives a double holding the initial account balance, a double holding the transaction fee to be applied to the balance and a double holding the month-end fee to be applied to the account. 
If the transaction fee received is positive-valued, this function stores the fee. If not, this function stores 0.0 as the fee to be applied. 
If the monthly fee received is positive-valued, this function stores the fee. If not, this function stores 0.0 as the fee to be applied.
*/
ChequingAccount::ChequingAccount(double initialBalance, double tFee, double monthendFee) :Account(initialBalance) {
    (tFee > 0) ? transactionFee = tFee : transactionFee = 0.0;
    (monthendFee > 0) ? monthlyFee = monthendFee : monthlyFee = 0.0;
}

/*
this modifier credits the balance by the amount received and if successful debits the transaction fee from the balance. 
This function returns true if the transaction succeeded; false otherwise.
*/
bool ChequingAccount::credit(double balance) {
    if(Account::credit(balance)) {
        Account::debit(transactionFee);
        return true;
    }
    return false;
}

/*
this modifier debits the balance by the amount received and if successful debits the transaction fee from the balance. 
This function returns true if the transaction succeeded; false otherwise.
*/
bool ChequingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        Account::debit(transactionFee);
        return true;
    }
    return false;
}

// this modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit.
void ChequingAccount::monthEnd() {
    Account::debit(monthlyFee);
}

// receives a reference to an ostream object and inserts the following output on separate lines to the object.
void ChequingAccount::display(std::ostream & os) const {
    os << "Account type: Chequing" << std::endl;
    os << "Balance: $" << std::fixed << std::setprecision(2) << Balance() << std::endl;
    os << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << transactionFee << std::endl;
    os << "Monthly Fee: " << std::fixed << std::setprecision(2) << monthlyFee << std::endl;
}