```Bash
$ g++ -std=c++23 -Wall -g -pthread main.cpp ../points/dto/*.cpp ../points/ui/*.cpp ../points/bus/*.cpp ../points/usecase/*.cpp -lgtest_main -lgtest -lpthread -o ./out/tests
```

## Chạy các tests và xem báo cáo
```Bash
$ ./out/tests
```