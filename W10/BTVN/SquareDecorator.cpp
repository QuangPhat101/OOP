#include "SquareDecorator.h"
SquareDecorator::SquareDecorator() {
  // Do nothing
}
void SquareDecorator::draw() const {
  if (this->_fillType == 1) {
    for (int i = 0; i < this->_size; ++i) {
      for (int j = 0; j < this->_size; ++j) {
        cout << this->_symbol;
      }
      cout << "\n";
    }
    cout << "\n\n";
  } else if (this->_fillType == 2)
    for (int i = 0; i < this->_size; ++i) {
      for (int j = 0; j < this->_size; ++j) {
        if (i == 0 || i == this->_size - 1 || j == 0 || j == this->_size - 1)
          cout << this->_symbol;
        else
          cout << " ";
      }
      cout << "\n";
    }
  cout << "\n\n";
}
