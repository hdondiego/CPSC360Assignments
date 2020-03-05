#include "loanacct.h"

// Hector Dondiego
// defining the getter and setter for IntRate
double LoanAcct::getIntRate(){
    return IntRate;
}

void LoanAcct::setIntRate(double rate){
    IntRate = rate;
}

// defining the PayBalance and CalcInterest functions
void LoanAcct::PayBalance(double pb){
    // paying off the loan
    setBalance(getBalance() - pb);
}

void LoanAcct::CalcInterest(){
    // the interest rate on the loan is reflected on to the Account's balance
    double mInterest = getBalance() * IntRate;
    setBalance(getBalance() + mInterest);
}
