#ifndef _PRODUCTEMPLOYEE_H_
#define _PRODUCTEMPLOYEE_H_
#include "Employee.h"
#include <iostream>
using std::to_string;

class ProductEmployee : public Employee {
private:
  int _productCount;
  int _paymentPerProduct;

public:
  int getProductCount();
  void setProductCount(int productCount);

  int getPaymentPerProduct();
  void setPaymentPerProduct(int paymentPerProduct);

public:
  int salary() override;
  ProductEmployee();
  string toString() override;
};

#endif