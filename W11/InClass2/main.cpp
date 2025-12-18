#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
private:
  int _day;
  int _month;
  int _year;

public:
  int day();
  int month();
  int year();

public:
  static Date now(); // Lấy ngày hiện tại
};

int Date::day() { return _day; }
int Date::month() { return _month; }
int Date::year() { return _year; }
Date Date::now() {
  Date today;
  today._day = 30;
  today._month = 4;
  today._year = 2025;
  return today;
}

class IConverter {
public:
  virtual string convert(const string &input) = 0;
};
class NormalizeCasing : public IConverter {
public:
  virtual string convert(const string &input) override;
};
class RemoveSpecialCharacters : public IConverter {
  virtual string convert(const string &input) override;
};
class AddDatePrefix : public IConverter {
  virtual string convert(const string &input) override;
};
string NormalizeCasing::convert(const string &input) {
  string result = input;
  bool first = true;
  int lastDotPos = input.find_last_of('.');
  for (int i = 0; i < result.size(); ++i) {
    if (first == true) {
      result[i] = toupper(result[i]);
      first = false;
    } else
      result[i] = tolower(result[i]);
    if (result[i] == ' ' || result[i] == '_' || result[i] == '-' ||
        (result[i] = '.' && i != lastDotPos)) {
      first = true;
    } else if (result[i] == '.' && i == lastDotPos) {
      first = false;
    }
  }
  return result;
}

string RemoveSpecialCharacters::convert(const string &input) {
  string result;
  int lastDotPos = input.find_last_of('.');
  for (int i = 0; i < input.size(); ++i) {
    if (isalnum(input[i]) || (i == lastDotPos && lastDotPos != string::npos)) {
      result.push_back(input[i]);
    }
  }
  return result;
}
string format(int number) {
  if (number > 10)
    return to_string(number);
  return "0" + to_string(number);
}
string AddDatePrefix::convert(const string &input) {
  string datePrefix;
  Date today = Date::now();
  datePrefix =
      format(today.year()) + format(today.month()) + format(today.day()) + "_";
  return datePrefix + input;
}
// TODO1: Sửa lớp này chứa luật
class RenameCVFileUseCase {
private:
  vector<IConverter *> converters;

public:
  void addConverter(IConverter *converter);
  string execute(const string &filename);
  // TODO2: cài đặt hàm execute
};
void RenameCVFileUseCase::addConverter(IConverter *converter) {
  converters.push_back(converter);
}
string RenameCVFileUseCase::execute(const string &filename) {
  string result = filename;
  for (IConverter *converter : converters) {
    result = converter->convert(result);
  }
  return result;
}

int main() {
  vector<string> filenames = {"Nguyen Van Minh.pDF", "Tran_Thi_Lan.DOCX",
                              "LE-HOANG_ANH.Pdf", "PhAm ..DUc ... HUy.Docx"};

  RenameCVFileUseCase batchRename;
  // TODO3: Đây là nơi bạn có thể viết thêm code để cấu hình
  // các quy tắc đổi tên sẽ được áp dụng.
  batchRename.addConverter(new NormalizeCasing());
  batchRename.addConverter(new RemoveSpecialCharacters());
  batchRename.addConverter(new AddDatePrefix());
  cout << "Renaming files...\n";
  for (const auto &origin : filenames) {
    auto renamed = batchRename.execute(origin);
    std::cout << origin << " -> " << renamed << "\n";
  }
  return 0;
}
