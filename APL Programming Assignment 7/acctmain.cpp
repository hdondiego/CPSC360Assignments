#include "checkingacct.h"
#include "loanacct.h"
#include <iostream>

// Hector Dondiego
// declaring a Template
template<class ACCT1>
void printInfo(ACCT1 &object);

int main(){
    CheckingAcct chAc1("Bob", 112, 100); // calling secondary constructor from CheckingAcct
    printInfo(chAc1);
    chAc1.Deposit(315); // adding 315 to the Balance
    printInfo(chAc1);
    chAc1.Withdraw(114); // subtracting 114 from Balance
    printInfo(chAc1);

    CheckingAcct chAc2; // calling default constructor from CheckingAcct
    chAc2.setOwnerName("John"); // setting the OwnerName, AcctNum, and Balance
    chAc2.setAcctNum(214);
    chAc2.setBalance(500);
    printInfo(chAc2);
    chAc2.Deposit(105); // adding 105 to Balance
    printInfo(chAc2);
    chAc2.Withdraw(275); // subtracting 275 from Balance
    printInfo(chAc2);

    // ------------------------------------------- //
    LoanAcct loAc1("Sarah", 2, 1.2, 250); // calling secondary constructor from LoanAcct
    printInfo(loAc1);
    loAc1.CalcInterest(); // getting the interest cost from multiplying the interest rate and Balance, and adding it to Balance
    printInfo(loAc1);
    loAc1.PayBalance(75); // paying 75 off the loan balance
    printInfo(loAc1);

    LoanAcct loAc2; // calling the default constructor from LoanAcct
    loAc2.setOwnerName("Jessica"); // setting the OwnerName, AcctNum, Balance, and interest rate
    loAc2.setAcctNum(654);
    loAc2.setBalance(120);
    loAc2.setIntRate(0.9);
    printInfo(loAc2);
    loAc2.CalcInterest(); // getting the interest cost from multiplying the interest rate and Balance, and adding it to Balance
    printInfo(loAc2);
    loAc2.PayBalance(90); // paying 90 off the loan balance
    printInfo(loAc2);

    return 0;
}

// defining the Template
// printing the attributes CheckingAcct and LoanAcct's Account attributes
// prints reflected changes to the accounts
template<class ACCT1>
void printInfo(ACCT1 &object){
    std::cout << "Owner Name: " << object.getOwnerName() << std::endl;
    std::cout << "Account Number: " << object.getAcctNum() << std::endl;
    std::cout << "Balance: " << object.getBalance() << std::endl;
    std::cout << std::endl;
}
