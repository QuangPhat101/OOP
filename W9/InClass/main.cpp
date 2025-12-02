#include "IShape.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>
#include <vector>
using std::cout, std::cin;
using std::vector; // using namespace std;

void salute(string message);
void bye();

int main() {
  salute("Chương trình tính diện tích và chu vi các hình");
  vector<IShape *> shapes = {new Rectangle(3, 5), new Square(5),
                             new Rectangle(7, 1), new Rectangle(6, 2),
                             new Square(9)};

  for (int i = 0; i < shapes.size(); ++i) {
    IShape *shape = shapes[i];
    // TODO: In ra thông tin của hình
    // Tên loại - Thông tin - Chu vi - Diện tích
    // Vuông: Cạnh=7, Chu vi=12, Diện tích=34
    // Chữ nhật: A=6, B=7, Chu vi=25, Diện tích=35
    cout << shape->toString() << "\n";
  }
  bye();
  return 0;
}

void salute(string message) { cout << message << " \n"; }
void bye() {
  cout << "Bấm enter để kết thúc chương trình...";
  cin.get();
}