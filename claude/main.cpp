#include <iostream>
#include <string>
#include <limits>
#include "OllamaClient.h"
#include "ChatSession.h"
#include "ngrok_url.h"

int main() {
    // Khởi tạo OllamaClient với model gpt-oss:20b
    OllamaClient client(OLLAMA_API_URL, "gpt-oss:20b");
    
    // Khởi tạo ChatSession
    ChatSession session(&client);
    
    // Bắt đầu phiên chat
    session.start();
    
    // Vòng lặp chat chính
    std::string userInput;
    while (session.active()) {
        std::cout << "\n👤 Bạn: ";
        
        // Clear input buffer trước khi đọc
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::getline(std::cin, userInput);
        
        // Trim whitespace
        userInput.erase(0, userInput.find_first_not_of(" \t\n\r"));
        userInput.erase(userInput.find_last_not_of(" \t\n\r") + 1);
        
        // Bỏ qua input rỗng
        if (userInput.empty()) {
            continue;
        }
        
        // Xử lý tin nhắn
        session.sendUserMessage(userInput);
    }
    
    return 0;
}