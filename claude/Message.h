#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>

// Class đại diện cho một tin nhắn trong cuộc hội thoại
class Message {
private:
    std::string role;      // "user" hoặc "assistant"
    std::string content;   // Nội dung tin nhắn
    time_t timestamp;      // Thời gian gửi

public:
    // Constructor
    Message(const std::string& role, const std::string& content);
    
    // Getters
    std::string getRole() const;
    std::string getContent() const;
    time_t getTimestamp() const;
    
    // Hiển thị tin nhắn
    void display() const;
    
    // Chuyển đổi sang JSON object (dùng cho API)
    std::string toJson() const;
};

#endif