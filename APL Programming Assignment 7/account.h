#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H
// Hector Dondiego
/*
Need to use ifndef because CheckingAcct
and LoanAcct both try to define Account.
Using ifndef will only have Account be
defined once.
*/
class Account{
    private:
        // private attributes
        std::string OwnerName;
        int AcctNum;
        double Balance;
    public:
        // prototype functions
        // getters and setters for private attributes
        std::string getOwnerName();
        void setOwnerName(std::string name);

        int getAcctNum();
        void setAcctNum(int num);

        double getBalance();
        void setBalance(double bal);

        // default and secondary constructors for Account
        Account();
        Account(std::string name, int id, int bal=0);
};
#endif
