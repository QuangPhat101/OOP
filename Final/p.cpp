#include <iostream>
#include <string>
using namespace std;

class Customer {
  string _name;
  int _id;

public:
  Customer(string name = "Unknown", int id = 0) : _name(name), _id(id) {
    cout << "Customer constructor\n";
  }
  Customer(const Customer &other) : _name(other._name), _id(other._id) {
    cout << "Customer copy constructor\n";
  }
  ~Customer() { cout << "Customer destructor\n"; }

  string name() const { return _name; }
  int id() const { return _id; }
};

class Account {
protected:
  Customer _customer;
  string _accName;

public:
  Account() : _customer(), _accName("") {
    cout << "Account default constructor\n";
  }

  Account(string accName, const Customer &c) : _customer(c), _accName(accName) {
    cout << "Account parameter constructor\n";
  }

  Account(const Account &other)
      : _customer(other._customer), _accName(other._accName) {
    cout << "Account copy constructor\n";
  }

  virtual ~Account() { cout << "Account destructor\n"; }

  virtual double balanceAfterYear() const = 0;

  virtual void display() const {
    cout << _accName << " - " << _customer.name() << endl;
  }
};

class SavingsAccount : public Account {
private:
  InterestPolicy _policy;
  double _balance;

public:
  SavingsAccount(const Customer &c, double bal, double rate)
      : Account("SavingsAccount", c), _policy(rate), _balance(bal) {
    cout << "SavingsAccount constructor\n";
  }

  SavingsAccount(const SavingsAccount &other)
      : Account(other), _policy(other._policy), _balance(other._balance) {
    cout << "SavingsAccount copy constructor\n";
  }

  double balanceAfterYear() const override {
    return _balance * (1.0 + _policy.rate());
  }

  void display() const override {
    cout << _accName << " - " << _customer.name() << ": " << balanceAfterYear()
         << endl;
  }

  ~SavingsAccount() override { cout << "SavingsAccount destructor\n"; }
};

class InterestPolicy {
  double _rate;

public:
  InterestPolicy(double rate = 0.0) : _rate(rate) {
    cout << "InterestPolicy constructor\n";
  }
  InterestPolicy(const InterestPolicy &other) : _rate(other._rate) {
    cout << "InterestPolicy copy constructor\n";
  }
  ~InterestPolicy() { cout << "InterestPolicy destructor\n"; }

  double rate() const { return _rate; }
};

void testByValue(SavingsAccount x) {
  cout << "== Inside testByValue ==\n";
  x.display();
  cout << "== Leaving testByValue ==\n";
}

void testByRef(const SavingsAccount &x) {
  cout << "== Inside testByRef ==\n";
  x.display();
  cout << "== Leaving testByRef ==\n";
}

int main() {
  cout << "== Create sa1 on stack ==\n";
  SavingsAccount sa1(Customer("Alice", 101), 1000.0, 0.05);

  cout << "== Call display() ==\n";
  sa1.display();

  cout << "== testByValue(sa1) ==\n";
  testByValue(sa1);

  cout << "== testByRef(sa1) ==\n";
  testByRef(sa1);

  cout << "== Polymorphism heap create ==\n";
  Account *p = new SavingsAccount(sa1);
  p->display();

  cout << "== delete p (virtual destructor check) ==\n";
  delete p;

  cout << "== End main ==\n";
  return 0;
}