
#include <format>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

template <typename T> struct Expected {
public:
  bool success;
  string message;
  T data;
};

template <typename T> Expected<T> succeed(T value) {
  return Expected<T>{true, "", value};
}

template <typename T> Expected<T> fail(string message) {
  return Expected<T>{false, message, T{}};
}

class ValidIntegerFormatValidator {
public:
  static bool isValid(const string &input) {
    regex intPattern(R"(^[+-]?\d+$)");
    return regex_match(input, intPattern);
  }
};
class IsPrimeValidator {
public:
  static bool isValid(int value) {
    if (value <= 1)
      return false;
    for (int i = 2; i * i <= value; ++i) {
      if (value % i == 0)
        return false;
    }
    return true;
  }
};
class ValidRangeValidator {
private:
  int minValue;
  int maxValue;

public:
  ValidRangeValidator(int minVal, int maxVal)
      : minValue(minVal), maxValue(maxVal) {}
  bool isValid(int value, int min, int max) const {
    return value >= minValue && value <= maxValue;
  }
};

// TODO01: Modify the class to store validators
class IntegerRequestUseCase {
private:
  int minValue;
  int maxValue;

private:
  ValidIntegerFormatValidator formatValidator;
  IsPrimeValidator primeValidator;
  ValidRangeValidator valueValidator;

public:
  IntegerRequestUseCase(int minVal, int maxVal)
      : minValue(minVal), maxValue(maxVal), valueValidator(minVal, maxVal) {}
  Expected<int> execute(string prompt);
};

// TODO02: You must modify this function
Expected<int> IntegerRequestUseCase::execute(string prompt) {
  cout << prompt;
  string buffer;
  getline(cin, buffer);
  if (formatValidator.isValid(buffer)) {
    int value = stoi(buffer);
    if (primeValidator.isValid(value)) {
      if (valueValidator.isValid(value, minValue, maxValue)) {
        return succeed<int>(value);
      } else {
        return fail<int>("Value out of range");
      }
    } else {
      return fail<int>("Not a prime number");
    }
  }
  return fail<int>("Invalid integer format");
}

int main() {
  int min = 1, max = 100;
  IntegerRequestUseCase useCase(min, max);
  // TODO03: Add validators here
  string prompt = format(
      "Please enter a prime number within the range of[{}, {}] : ", min, max);
  auto result = useCase.execute(prompt);
  if (result.success) {
    cout << "You entered a prime : " << result.data << endl;
  } else {
    cout << "Error : " << result.message << endl;
  }
  return 0;
}
