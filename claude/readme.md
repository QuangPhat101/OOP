# 🎓 Chatbot Trợ Lý Học Lập Trình - Đồ Án OOP

## 📋 Mô tả dự án
Chatbot AI hỗ trợ học lập trình, xây dựng bằng C++ với kiến trúc OOP. Sử dụng Ollama API để tạo trải nghiệm chat streaming (hiển thị câu trả lời theo thời gian thực).

## 🏗️ Kiến trúc OOP

### 1. **Class Message** (`Message.h`, `Message.cpp`)
- **Mục đích**: Đại diện cho một tin nhắn trong cuộc hội thoại
- **Thuộc tính**: 
  - `role` (user/assistant)
  - `content` (nội dung)
  - `timestamp` (thời gian)
- **Phương thức**: `display()`, `toJson()`, getters

### 2. **Class OllamaClient** (`OllamaClient.h`, `OllamaClient.cpp`)
- **Mục đích**: Xử lý giao tiếp với Ollama API
- **Thuộc tính**: `apiUrl`, `model`, `curl`
- **Phương thức**: 
  - `sendMessage()` - gửi tin nhắn với streaming
  - `StreamCallback()` - xử lý response streaming
  - `setModel()`, `getModel()`

### 3. **Class ChatSession** (`ChatSession.h`, `ChatSession.cpp`)
- **Mục đích**: Quản lý phiên chat và lịch sử hội thoại
- **Thuộc tính**: `history`, `client`, `isActive`
- **Phương thức**: 
  - `start()`, `stop()` - điều khiển phiên
  - `sendUserMessage()` - gửi tin nhắn
  - `clearHistory()`, `showHistory()` - quản lý lịch sử
  - `showHelp()` - hiển thị trợ giúp

## 📦 Cấu trúc thư mục
```
chatbot-oop/
├── Message.h
├── Message.cpp
├── OllamaClient.h
├── OllamaClient.cpp
├── ChatSession.h
├── ChatSession.cpp
├── main.cpp
├── ngrok_url.h
├── json.hpp          # Từ nlohmann/json
├── Makefile
└── README.md
```

## ⚙️ Yêu cầu hệ thống
- **Compiler**: g++ với C++11 trở lên
- **Thư viện**: 
  - libcurl (cài đặt: `sudo apt install libcurl4-openssl-dev`)
  - nlohmann/json (header-only, đã include)
- **Ollama server**: Đang chạy và expose qua ngrok

## 🚀 Cách build và chạy

### Build:
```bash
make
```

### Chạy:
```bash
./chatbot
```

Hoặc:
```bash
make run
```

### Clean:
```bash
make clean
```

## 💡 Cách sử dụng

### Các lệnh có sẵn:
- `/help` - Hiển thị hướng dẫn
- `/history` - Xem lịch sử hội thoại
- `/clear` - Xóa lịch sử
- `/exit` hoặc `/quit` - Thoát chương trình

### Ví dụ hội thoại:
```
👤 Bạn: Giải thích con trỏ trong C++

🤖 AI: Con trỏ là biến lưu địa chỉ bộ nhớ...
(streaming response)

👤 Bạn: Cho tôi ví dụ code

🤖 AI: Đây là ví dụ về con trỏ:
int x = 10;
int* ptr = &x;
...
```

## 🎯 Tính năng nổi bật

1. ✅ **Streaming Response**: Hiển thị câu trả lời theo thời gian thực như ChatGPT
2. ✅ **Context Memory**: Lưu lịch sử hội thoại để AI nhớ ngữ cảnh
3. ✅ **System Prompt**: Được tối ưu cho hỗ trợ học lập trình
4. ✅ **Command System**: Các lệnh dễ dùng (/help, /clear...)
5. ✅ **OOP Design**: Áp dụng đầy đủ tính chất OOP (Encapsulation, Abstraction)

## 🔧 Tuỳ chỉnh

### Đổi model:
Trong `main.cpp`:
```cpp
OllamaClient client(OLLAMA_API_URL, "llama3");  // Đổi model
```

### Đổi system prompt:
Trong `OllamaClient.cpp`, method `sendMessage()`:
```cpp
{"content", "Bạn là trợ lý AI..."}  // Sửa ở đây
```

## 📝 Báo cáo đồ án

### Các điểm cần trình bày:
1. **Phân tích yêu cầu**: Chatbot học lập trình với streaming
2. **Thiết kế OOP**: 
   - Class diagram (3 classes)
   - Mối quan hệ: ChatSession HAS-A OllamaClient, USES Message
3. **Tính chất OOP áp dụng**:
   - Encapsulation (private/public)
   - Abstraction (ẩn chi tiết CURL, streaming)
   - Có thể mở rộng: Inheritance (tạo SpecializedChatbot extends ChatSession)
4. **Kết quả**: Demo chạy chương trình

## 🐛 Xử lý lỗi thường gặp

### Lỗi: `undefined reference to curl_*`
→ Thiếu `-lcurl` khi compile. Dùng Makefile đã cung cấp.

### Lỗi: Cannot connect to API
→ Kiểm tra `ngrok_url.h` có đúng URL không, Ollama server có đang chạy không.

### Streaming không hoạt động
→ Kiểm tra `"stream": true` trong `OllamaClient.cpp`

## 📚 Tài liệu tham khảo
- [Ollama API Documentation](https://github.com/ollama/ollama/blob/main/docs/api.md)
- [nlohmann/json](https://github.com/nlohmann/json)
- [libcurl](https://curl.se/libcurl/)

---
**Sinh viên thực hiện**: [Tên của bạn]  
**Lớp**: [Lớp của bạn]  
**Môn học**: Lập trình hướng đối tượng (OOP)