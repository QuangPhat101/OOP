#include "ProductEmployee.h"

int ProductEmployee::salary() { return _productsCount * _paidPerProduct; }
ProductEmployee::ProductEmployee() {
  _productsCount = 0;
  _paidPerProduct = 0;
}
ProductEmployee::ProductEmployee(string name, int productsCount,
                                 int paidPerProduct)
    : Employee(name) {
  _productsCount = productsCount;
  _paidPerProduct = paidPerProduct;
}
ProductEmployee::~ProductEmployee() {
  // Do nothing
}