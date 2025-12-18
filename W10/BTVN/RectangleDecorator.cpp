#include "RectangleDecorator.h"

RectangleDecorator::RectangleDecorator() {
  // Do nothing
}
void RectangleDecorator::draw() const {
  if (this->_fillType == 1) {
    for (int i = 0; i < this->_height; ++i) {
      for (int j = 0; j < this->_width; ++j)
        cout << this->_symbol;
      cout << "\n";
    }
    cout << "\n\n";
  } else if (this->_fillType == 2) {
    for (int i = 0; i < this->_height; ++i) {
      for (int j = 0; j < this->_width; ++j) {
        if (i == 0 || i == this->_height - 1 || j == this->_width - 1 || j == 0)
          cout << this->_symbol;
        else
          cout << " ";
      }
      cout << "\n";
    }
    cout << "\n\n";
  }
}