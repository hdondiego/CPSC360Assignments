g++ -c account.cpp
g++ -c checkingacct.cpp
g++ -c loanacct.cpp
g++ -c acctmain.cpp
g++ account.o checkingacct.o loanacct.o acctmain.o -o account.exe
