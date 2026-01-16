#include "ChatSession.h"
#include <iostream>

ChatSession::ChatSession(OllamaClient* ollamaClient) 
    : client(ollamaClient), isActive(false) {
}

ChatSession::~ChatSession() {
    // Không delete client vì nó được quản lý bên ngoài
}

void ChatSession::start() {
    isActive = true;
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║   🎓 TRỢ LÝ HỌC LẬP TRÌNH - CHATBOT AI                 ║\n";
    std::cout << "║   Model: " << client->getModel() << std::string(40 - client->getModel().length(), ' ') << "      ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n";
    std::cout << "\nGõ /help để xem hướng dẫn, /exit để thoát.\n";
}

void ChatSession::stop() {
    isActive = false;
    std::cout << "\n👋 Tạm biệt! Chúc bạn học tập tốt!\n";
}

bool ChatSession::active() const {
    return isActive;
}

void ChatSession::sendUserMessage(const std::string& message) {
    // Kiểm tra các lệnh đặc biệt
    if (message == "/exit" || message == "/quit") {
        stop();
        return;
    }
    
    if (message == "/clear") {
        clearHistory();
        std::cout << "✅ Đã xóa lịch sử hội thoại.\n";
        return;
    }
    
    if (message == "/history") {
        showHistory();
        return;
    }
    
    if (message == "/help") {
        showHelp();
        return;
    }
    
    // Lệnh mới: đổi model
    if (message.substr(0, 7) == "/model ") {
        std::string newModel = message.substr(7);
        client->setModel(newModel);
        std::cout << "✅ Đã đổi sang model: " << newModel << "\n";
        std::cout << "💡 Nhớ chạy 'ollama pull " << newModel << "' trên server nếu chưa có!\n";
        return;
    }
    
    // Hiển thị tin nhắn người dùng
    Message userMsg("user", message);
    
    // Gửi đến AI và nhận phản hồi (streaming)
    std::string response = client->sendMessage(history, message);
    
    // Lưu vào lịch sử
    history.push_back(userMsg);
    history.push_back(Message("assistant", response));
}

void ChatSession::clearHistory() {
    history.clear();
}

void ChatSession::showHistory() const {
    if (history.empty()) {
        std::cout << "📭 Chưa có lịch sử hội thoại.\n";
        return;
    }
    
    std::cout << "\n📜 ═══ LỊCH SỬ HỘI THOẠI ═══\n";
    for (const auto& msg : history) {
        msg.display();
    }
    std::cout << "═══════════════════════════\n";
}

void ChatSession::showHelp() const {
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║                  📖 HƯỚNG DẪN SỬ DỤNG                  ║\n";
    std::cout << "╠════════════════════════════════════════════════════════╣\n";
    std::cout << "║  /help     - Hiển thị hướng dẫn này                    ║\n";
    std::cout << "║  /history  - Xem lịch sử hội thoại                     ║\n";
    std::cout << "║  /clear    - Xóa lịch sử hội thoại                     ║\n";
    std::cout << "║  /exit     - Thoát chương trình                        ║\n";
    std::cout << "╠════════════════════════════════════════════════════════╣\n";
    std::cout << "║  💡 MẸO: Hỏi về lập trình, giải thuật, debug code...   ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n";
}