#include <iostream>
#include <vector>
#include <format>
using namespace std;

#include "bus/app.h"
#include "dao/mock_account_repository.h"
#include "dto/Account.h"

int main()
{
    App app;
    app.loadAccounts();

    int amount = 70000;
    app.withdraw(amount);
}
