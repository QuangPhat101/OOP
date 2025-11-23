#include <format>
#include <iostream>
#include <vector>
using namespace std;

const int MIN_WITHDRAW = 50000;

class Account {
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

class MockAccountRepository {
 public:
  vector<Account> getAll();
};

class App {
 private:
  vector<Account> _accounts;

 public:
  void loadAccounts();
  // Thực hiện rút tiền cho tất cả các tài khoản cùng một lượng tiền
  void withdraw(int amount);
};

string formatWithdrawOutput(const int& withdraw);

// Hàm main

int main() {
  App app;
  app.loadAccounts();
  int amount = 70000;
  app.withdraw(amount);
}

string Account::name() { return _name; }

int Account::balance() { return _balance; }

Account::Account() {
  _name = "";
  _balance = 0;
}

Account::Account(string name, int balance) : _name(name), _balance(balance) {
  // Do nothing
}

int Account::withdraw(int amount) {
  if (_balance >= amount) {
    int result = 0;
    while (result < amount) {
      result += MIN_WITHDRAW;
    }
    result -= MIN_WITHDRAW;
    return result;
  }
  return 0;
}
vector<Account> MockAccountRepository::getAll() {
  return vector<Account>{
      Account("Alice", 60000),    Account("Bob", 100000),
      Account("Charlie", 100000), Account("David", 200000),
      Account("Eve", 300000),
  };
}

void App::loadAccounts() {
  MockAccountRepository repo;
  this->_accounts = repo.getAll();
}

void App::withdraw(int amount) {
  for (auto& account : _accounts) {
    std::cout << format("{} has {}, can withdraw {} \n", account.name(),
                        formatWithdrawOutput(account.balance()),
                        formatWithdrawOutput(account.withdraw(amount)));
  }
}
string formatWithdrawOutput(const int& withdraw) {
  string result = "";
  int temp = withdraw;
  while (temp / 10 != 0) {
    int i = temp % 10;
    result.push_back(i + '0');
    temp /= 10;
  }
  result.push_back(temp + '0');
  std::reverse(result.begin(), result.end());
  for (int i = result.length() - 3; i > 0; i -= 3) {
    result.insert(i, ".");
  }
  return result;
}