#ifndef _FLOAT_H_
#define _FLOAT_H_
#include <string>
#include <expected>
using std::string;
using std::expected;

// TODO: chưa bổ sung comment
// TODO: Tạo ra tài liệu mô tả mã nguồn
class Float {
public:
    static expected<float, string> getFloat(string message);
    static float getFloatLoop(string message);
    static expected<float, string> getFloatRetry(string message, int maxAttempts = 3);
};

#endif