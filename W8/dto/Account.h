#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
using std::string;

const int MIN_WITHDRAW_AMOUNT = 50000;

class Account
{
protected:
    string _name;
    int _balance;

public:
    string name();
    int balance();

public:
    Account();
    Account(string name, int balance);

public:
    // Trả ra số tiền có thể rút
    int withdraw(int amount);
};

#endif