#ifndef OLLAMA_CLIENT_H
#define OLLAMA_CLIENT_H

#include <string>
#include <vector>
#include <curl/curl.h>
#include "Message.h"
#include "json.hpp"

using json = nlohmann::json;

// Class xử lý giao tiếp với Ollama API
class OllamaClient {
private:
    std::string apiUrl;
    std::string model;
    CURL* curl;
    
    // Callback cho libcurl (streaming)
    static size_t StreamCallback(void* contents, size_t size, size_t nmemb, void* userp);
    
public:
    // Constructor & Destructor
    OllamaClient(const std::string& url, const std::string& modelName);
    ~OllamaClient();
    
    // Gửi tin nhắn và nhận phản hồi (streaming)
    std::string sendMessage(const std::vector<Message>& history, const std::string& userMessage);
    
    // Getters/Setters
    void setModel(const std::string& modelName);
    std::string getModel() const;
};

#endif