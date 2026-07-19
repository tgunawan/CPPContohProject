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

std::size_t len(const std::string& text) {
    return text.size();
}

std::vector<int> range(int end) {
    return range(0, end, 1);
}

std::vector<int> range(int start, int end) {
    return range(start, end, 1);
}

std::vector<int> range(int start, int end, int step) {
    std::vector<int> values;
    if (step == 0) {
        return values;
    }
    if (step > 0) {
        for (int i = start; i < end; i += step) {
            values.push_back(i);
        }
    } else {
        for (int i = start; i > end; i += step) {
            values.push_back(i);
        }
    }
    return values;
}
