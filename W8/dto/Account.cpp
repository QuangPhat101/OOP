#include "Account.h"

string Account::name()
{
    return _name;
}

int Account::balance()
{
    return _balance;
}

Account::Account()
{
    _name = "";
    _balance = 0;
}
Account::Account(string name, int balance) : _name(name), _balance(balance)
{
    // Do nothing
}

int Account::withdraw(int amount)
{
    int result = amount;
    while (result % MIN_WITHDRAW_AMOUNT != 0)
    {
        result
    }
    if (this->balance() >= amount)
        return 0;
}