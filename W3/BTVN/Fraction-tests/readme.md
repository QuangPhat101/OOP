## Biên dịch & chạy
```Bash
$ g++ -std=c++23 Fraction-tests/main.cpp Fraction/Fraction.cpp Fraction/Int.cpp Fraction/usecase.cpp -o app -lgtest -lgtest_main -lpthread
```

```Bash
$ ./test
```