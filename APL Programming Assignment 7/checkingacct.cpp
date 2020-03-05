#include "checkingacct.h"

// Hector Dondiego
// defining the Deposit and Withdraw functions
void CheckingAcct::Deposit(double dep){
    // adding to Balance
    setBalance(getBalance() + dep);
}

void CheckingAcct::Withdraw(double with){
    // subtracting from Balance
    setBalance(getBalance() - with);
}
