#include "Mock_account_repository.h"

vector<Account> MockAccountRepository::getAll()
{
    return vector<Account>{
        Account("Alice", 60000),
        Account("Bob", 100000),
        Account("Charlie", 100000),
        Account("David", 200000),
        Account("Eve", 300000),
    };
}
