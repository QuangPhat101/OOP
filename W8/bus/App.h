#ifndef _APP_H_
#define _APP_H_

#include "../dto/Account.h"
#include "../dao/Mock_account_repository.h"
#include "../ui/Withdraw.h "
#include <iostream>
#include <vector>
using std::vector;

class App
{
private:
    vector<Account> _accounts;

public:
    void loadAccounts();
    // Thực hiện rút tiền cho tất cả các tài khoản cùng một lượng tiền
    void withdraw(int amount);
};
#endif