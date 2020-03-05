#include "account.h"

// Hector Dondiego
// defining the prototype functions from account.h
// defining the getters and setters
std::string Account::getOwnerName(){
    return OwnerName;
}

void Account::setOwnerName(std::string name){
    OwnerName = name;
}

int Account::getAcctNum(){
    return AcctNum;
}

void Account::setAcctNum(int num){
    AcctNum = num;
}

double Account::getBalance(){
    return Balance;
}

void Account::setBalance(double bal){
    Balance = bal;
}

// defining the constructors
// defining the default constructor
Account::Account(){
    OwnerName = "No name";
    AcctNum = 0;
    Balance = 0;
}

// defining the secondary constructor
Account::Account(std::string name, int id, int bal){
    OwnerName = name;
    AcctNum = id;
    Balance = bal;
}
