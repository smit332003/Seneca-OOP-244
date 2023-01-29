/*==============================================
    Name: Smitkumar K PATEL
   Student Number: 157308214
   Email: spatel556@myseneca.ca  
   Date: JUL 22 2022          
   Workshop: 8 Part- 1     
   I have done all the coding by myself and only copied the code that
   my professor provided to complete my workshops and assignments. 
  ==============================================*/
  #include "SavingsAccount.h"

/*
constructor receives a double holding the initial account balance and a double holding the interest rate to be applied to the balance. 
If the interest rate received is positive-valued, this function stores the rate. If not, this function stores 0.0 as the rate to be applied.
*/
SavingsAccount::SavingsAccount(double balance, double iRate) :Account(balance) {
    if (iRate > 0.0)
        interestRate = iRate;
    else
        interestRate = 0.0;
}

// this modifier calculates the interest earned on the current balance and credits the account with that interest.
void SavingsAccount::monthEnd() {
    auto interest = this->Balance() * interestRate; // allocator.cpp - double interestRate = 0.05; 
    credit(interest);
}

// receives a reference to an ostream object and inserts the following output on separate lines to the object. 
void SavingsAccount::display(std::ostream& os) const {
    os << "Account type: Savings" << std::endl;
    os << "Balance: $" << std::fixed << std::setprecision (2) << Balance() << std::endl;
    os << "Interest Rate (%): " << std::fixed << std::setprecision (2) << (interestRate * 100.00) << std::endl;
}