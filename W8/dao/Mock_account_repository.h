#ifndef _MOCK_ACCOUNT_REPOSITORY_H_
#define _MOCK_ACCOUNT_REPOSITORY_H_

#include "../dto/Account.h"
#include <vector>
using std::vector;

class MockAccountRepository
{
public:
    vector<Account> getAll();
};

#endif