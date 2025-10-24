```Bash
$ g++ -std=c++23 -Wall -g -pthread main.cpp ../Fraction/dto/*.cpp ../Fraction/ui/*.cpp ../Fraction/bus/*.cpp ../Fraction/usecase/*.cpp -lgtest_main -lgtest -lpthread -o ./out/tests
```

```Bash
$ ./out/tests
```