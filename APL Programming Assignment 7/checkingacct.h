#include "account.h"

// Hector Dondiego
class CheckingAcct : public Account{
    public:
        // prototype constructor functions for default and secondary constructors
        CheckingAcct() : Account(){}
        CheckingAcct(std::string name, int id, int bal=0) : Account(name, id, bal){}

        // prototype functions for Deposit and Withdraw
        void Deposit(double dep);

        void Withdraw(double with);
};
