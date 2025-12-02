# Makefile để build chatbot OOP

CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra
LDFLAGS = -lcurl

# Tên file thực thi
TARGET = chatbot

# Các file nguồn
SOURCES = main.cpp Message.cpp OllamaClient.cpp ChatSession.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# File header
HEADERS = Message.h OllamaClient.h ChatSession.h ngrok_url.h json.hpp

# Build all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild
rebuild: clean all

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run