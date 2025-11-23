#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <vector>
#include <string>
#include "Message.h"
#include "OllamaClient.h"

// Class quản lý một phiên chat
class ChatSession {
private:
    std::vector<Message> history;  // Lịch sử hội thoại
    OllamaClient* client;          // Con trỏ đến OllamaClient
    bool isActive;                 // Trạng thái phiên
    
public:
    // Constructor & Destructor
    ChatSession(OllamaClient* ollamaClient);
    ~ChatSession();
    
    // Gửi tin nhắn và nhận phản hồi
    void sendUserMessage(const std::string& message);
    
    // Quản lý lịch sử
    void clearHistory();
    void showHistory() const;
    
    // Điều khiển phiên
    void start();
    void stop();
    bool active() const;
    
    // Hiển thị trợ giúp
    void showHelp() const;
};

#endif