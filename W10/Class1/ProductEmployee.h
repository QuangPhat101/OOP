#ifndef _PRODUCTEMPLOYEE_H_
#define _PRODUCTEMPLOYEE_H_

#include "Employee.h"
class ProductEmployee : public Employee {
private:
  int _productsCount;
  int _paidPerProduct;

public:
  int salary() override;
  ProductEmployee();
  ProductEmployee(string name, int productsCount, int paidPerProduct);
  ~ProductEmployee() override;
};

#endif