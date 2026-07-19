#include "pythonlike.h"

void print(const std::string& text) {
    std::cout << text;
}

void print(const std::string& text, const std::string& end) {
    std::cout << text << end;
}

void print(const std::string& text, const char* end) {
    std::cout << text << end;
}

std::string input(const std::string& prompt) {
    if (!prompt.empty()) {
        std::cout << prompt;
    }
    std::string value;
    std::getline(std::cin, value);
    return value;
}
