#include "OllamaClient.h"
#include <iostream>
#include <sstream>

OllamaClient::OllamaClient(const std::string& url, const std::string& modelName) 
    : apiUrl(url), model(modelName) {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

OllamaClient::~OllamaClient() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Callback để xử lý streaming response - PHIÊN BẢN CẢI TIẾN
size_t OllamaClient::StreamCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* buffer = (std::string*)userp;
    
    // Thêm data vào buffer
    std::string newData((char*)contents, totalSize);
    *buffer += newData;
    
    // Parse từng dòng JSON (NDJSON format)
    size_t pos = 0;
    while ((pos = buffer->find('\n')) != std::string::npos) {
        std::string line = buffer->substr(0, pos);
        buffer->erase(0, pos + 1);
        
        // Bỏ qua dòng trống
        if (line.empty() || line == "\r") {
            continue;
        }
        
        try {
            json chunk = json::parse(line);
            
            // Kiểm tra có content không
            if (chunk.contains("message")) {
                if (chunk["message"].contains("content")) {
                    std::string content = chunk["message"]["content"];
                    if (!content.empty()) {
                        std::cout << content << std::flush;
                    }
                }
            }
            
            // Kiểm tra done flag (kết thúc streaming)
            if (chunk.contains("done") && chunk["done"].is_boolean() && chunk["done"]) {
                // Streaming hoàn tất
            }
            
        } catch (const json::parse_error& e) {
            // Log lỗi parse nhưng không crash
            // std::cerr << "\n[Debug] JSON parse error: " << e.what() << std::endl;
            // std::cerr << "[Debug] Line: " << line << std::endl;
        } catch (...) {
            // Bỏ qua các lỗi khác
        }
    }
    
    return totalSize;
}

std::string OllamaClient::sendMessage(const std::vector<Message>& history, const std::string& userMessage) {
    if (!curl) {
        return "Lỗi: CURL chưa được khởi tạo.";
    }
    
    // Tạo JSON payload
    json requestData;
    requestData["model"] = model;
    requestData["stream"] = true;
    
    // Thêm options để AI trả lời đầy đủ hơn - TĂNG CAO HỠN
    requestData["options"] = {
        {"num_predict", 4096},       // Tối đa 4096 tokens (tăng mạnh!)
        {"temperature", 0.7},        // Độ sáng tạo vừa phải
        {"top_p", 0.9},             // Nucleus sampling
        {"top_k", 40},              // Top-k sampling
        {"repeat_penalty", 1.1}     // Tránh lặp lại
    };
    
    // Thêm system prompt - Cải tiến để AI thông minh hơn
    json messages = json::array();
    messages.push_back({
        {"role", "system"},
        {"content", R"(Bạn là trợ lý AI chuyên gia về lập trình C++.

QUY TẮC TRẢ LỜI:
1. Trả lời TRỰC TIẾP vào vấn đề, không dài dòng sáo rỗng
2. LUÔN kèm code example cụ thể khi giải thích khái niệm
3. Giải thích đơn giản như đang dạy sinh viên năm 2
4. Nếu câu hỏi về lỗi code, CHỈ RA lỗi và ĐƯA RA code đúng
5. Format code rõ ràng với comment tiếng Việt
6. Không chú thích kiểu như dùng **
7. Khi thấy người dùng ghi có chữ exit thì tạm biệt chứ không lặp lại câu trả lời cũ 

VÍ DỤ TRẢ LỜI TỐT:
Q: "Con trỏ là gì?"
A: "Con trỏ là biến lưu địa chỉ ô nhớ. Ví dụ:
```cpp
int x = 10;
int* ptr = &x;  // ptr lưu địa chỉ của x
cout << *ptr;   // In giá trị: 10
```"

TRÁNH: Nói chung chung như "con trỏ là khái niệm quan trọng...", "có nhiều cách dùng...")"
        }
    });
    
    // Thêm lịch sử hội thoại
    for (const auto& msg : history) {
        messages.push_back({
            {"role", msg.getRole()},
            {"content", msg.getContent()}
        });
    }
    
    // Thêm tin nhắn hiện tại
    messages.push_back({
        {"role", "user"},
        {"content", userMessage}
    });
    
    requestData["messages"] = messages;
    std::string payload = requestData.dump();
    
    // Cấu hình CURL
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    
    std::string responseBuffer;
    
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StreamCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    
    std::cout << "🤖 AI: " << std::flush;
    
    // Thực hiện request
    CURLcode res = curl_easy_perform(curl);
    std::cout << "\n"; // Xuống dòng sau khi streaming xong
    
    curl_slist_free_all(headers);
    
    if (res != CURLE_OK) {
        return "Lỗi kết nối: " + std::string(curl_easy_strerror(res));
    }
    
    // Trả về nội dung đầy đủ (để lưu vào history)
    // Parse lại buffer để lấy full response
    std::stringstream ss(responseBuffer);
    std::string line, fullResponse;
    
    while (std::getline(ss, line)) {
        if (line.empty() || line == "\r") continue;
        
        try {
            json chunk = json::parse(line);
            
            // Lấy content từ message
            if (chunk.contains("message") && chunk["message"].contains("content")) {
                fullResponse += chunk["message"]["content"].get<std::string>();
            }
            
            // Nếu gặp done = true, dừng lại
            if (chunk.contains("done") && chunk["done"].is_boolean() && chunk["done"]) {
                break;
            }
            
        } catch (...) {
            // Bỏ qua lỗi parse
        }
    }
    
    // Nếu không lấy được gì, trả về thông báo lỗi
    if (fullResponse.empty()) {
        return "[Lỗi: Không nhận được phản hồi từ AI. Thử lại hoặc đổi model.]";
    }
    
    return fullResponse;
}

void OllamaClient::setModel(const std::string& modelName) {
    model = modelName;
}

std::string OllamaClient::getModel() const {
    return model;
}