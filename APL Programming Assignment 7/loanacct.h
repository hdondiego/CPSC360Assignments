#include "account.h"

// Hector Dondiego
class LoanAcct : public Account{
    private:
        // private attribute
        double IntRate;
    public:
        // defining the default and secondary constructors
        LoanAcct() : Account(){}
        LoanAcct(std::string name, int id, double rate=0, int bal=0) : Account(name, id, bal){
            IntRate = rate;
        }

        // prototype functions for getter and setter for IntRate
        double getIntRate();
        void setIntRate(double rate);

        // prototype functions for PayBalance and CalcInterest
        void PayBalance(double pb);

        void CalcInterest();
};
