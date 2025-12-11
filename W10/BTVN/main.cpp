#include <iostream>
using namespace std;

void find(int x) {
  int count = 1;
  int value;
  while (count <= 30) {
    cout << " Nhập câu trả lời: ";
    cin >> value;
    if (value < x) {
      cout << "Yes\n";
    } else if (value > x)
      cout << "No\n";
    else
      break;
  }
  if (value == x)
    cout << "Tìm thấy\n";
  else
    cout << "Không tìm thấy\n";
}
int main() {
  find(1000000);
  return 0;
}