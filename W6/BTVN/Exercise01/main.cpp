#include "matrix.h"
#include <iostream>
using std::cout;


int main(){
     Matrix a(2, 3); // 2 dòng 3 cột
     a.setValue(0, 0, 97);
     a.setValue(0, 1, 98);
     a.setValue(0, 2, 99);

     a.setValue(1, 0, 100);
     a.setValue(1, 1, 101);
     a.setValue(1, 2, 102);
     cout << a << "\n";

     Matrix b = a; // Chú ý hàm tạo sao chép lại được gọi chứ không phải operator= được gọi
     b.setValue(0, 0, 234); 
     b.setValue(1, 1, 777);
     cout << b;
     return 0;
}