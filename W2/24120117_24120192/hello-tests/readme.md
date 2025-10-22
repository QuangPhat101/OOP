## Biên dịch & chạy
```Bash
$ cd hello-tests
```

```Bash
$ g++ -std=c++23 -Wall -g -pthread main.cpp ../hello/usecase.cpp ../lib/*.cpp -lgtest_main -lgtest -lpthread -o ./out/app
```

```Bash
$ ./out/app
```