#include "Float.h"
#include <iostream>
#include <format>
#include <regex>
using std::regex, std::regex_match;
using std::cout, std::cin;
using std::unexpected;
using std::format;

expected<float, string> Float::getFloat(string message) {
    cout << message;
    
    string buffer;
    getline(cin, buffer);
    
    // 1. Rỗng - Edge case
    if (buffer.length() == 0) {
       return unexpected("Empty input data");  
    }  
    
    // Giáo viên sẽ sửa
    // 2. TODO: Không đúng định dạng ==> regular expression
    regex numberPattern(R"(\d+)");
	bool matched = regex_match(buffer, numberPattern);
	if(!matched){
        return unexpected("Invalid value");
    }
    // 3. TODO: Không đúng miền giá trị ==> TODO: chưa xét

    // Main success scenario / Happy path
    float value = stof(buffer);
    return value;
}

float Float::getFloatLoop(string message) {
    expected<float, string> result;
    
    do {
        result = Float::getFloat(message);
        
        if (!result.has_value()){
            cout << "Lỗi nhập liệu: " << result.error() << "\n";
            cout << "Vui lòng nhập lại.\n";
        }
    } while (!result.has_value());    
    
    return result.value();
}

expected<float, string> Float::getFloatRetry(string message, int maxAttempts) {
    int failCount = 0;
    expected<float, string> result;
    
    do {
        result = Float::getFloat(message);
        
        if (!result.has_value()){
            failCount++;
            cout << "Lỗi nhập liệu: " << result.error() << "\n";
            
            if (failCount != maxAttempts ) {
                cout << "Vui lòng nhập lại. Bạn còn " << maxAttempts - failCount << " lần thử\n";
            }  
        }
    } while (!result.has_value() 
        && (failCount != maxAttempts)
    );
    
    if (failCount == maxAttempts) {
        return unexpected(format(
            "Bạn đã nhập quá số lần cho phép là: {}", 
            maxAttempts
        ));
    }
    
    return result.value();}