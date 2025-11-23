#include "App.h"

void App::loadAccounts()
{
    MockAccountRepository repo;
    _accounts = repo.getAll();
}

void App::withdraw(int amount)
{
    for (auto &account : _accounts)
    {
        std::cout << format(
            "{} has {}, can withdraw {} \n",
            account.name(),
            formatWithdrawOutput(account.balance()),
            formatWithdrawOutput(account.withdraw(amount)));
    }
}