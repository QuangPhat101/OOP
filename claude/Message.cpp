#include "Message.h"
#include <iostream>
#include <iomanip>

Message::Message(const std::string& role, const std::string& content) 
    : role(role), content(content) {
    timestamp = std::time(nullptr);
}

std::string Message::getRole() const {
    return role;
}

std::string Message::getContent() const {
    return content;
}

time_t Message::getTimestamp() const {
    return timestamp;
}

void Message::display() const {
    // Hiển thị tin nhắn với format đẹp
    std::string prefix = (role == "user") ? "👤 Bạn: " : "🤖 AI: ";
    std::cout << "\n" << prefix << content << "\n";
}

std::string Message::toJson() const {
    // Chuyển sang format JSON đơn giản (không dùng thư viện)
    return "{\"role\":\"" + role + "\",\"content\":\"" + content + "\"}";
}