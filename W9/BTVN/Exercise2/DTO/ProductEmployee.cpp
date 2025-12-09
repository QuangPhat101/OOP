#include "ProductEmployee.h"

int ProductEmployee::salary() { return _productCount * _paymentPerProduct; }
int ProductEmployee::getProductCount() { return _productCount; }
void ProductEmployee::setProductCount(int productCount) {
  _productCount = productCount;
}
int ProductEmployee::getPaymentPerProduct() { return _paymentPerProduct; }
void ProductEmployee::setPaymentPerProduct(int paymentPerProduct) {
  _paymentPerProduct = paymentPerProduct;
}
ProductEmployee::ProductEmployee() {
  _productCount = 0;
  _paymentPerProduct = 0;
}
string ProductEmployee::toString() { return "ProductEmployee"; }