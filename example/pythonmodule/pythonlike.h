#ifndef PYTHONLIKE_H
#define PYTHONLIKE_H

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>

void print(const std::string& text);
void print(const std::string& text, const std::string& end);
void print(const std::string& text, const char* end);

template <typename T>
void print(const T& value) {
    std::cout << value;
}

template <typename T>
void print(const T& value, const std::string& end) {
    std::cout << value << end;
}

template <typename T>
void print(const std::string& end,const T& value) {
    std::cout << value << end;
}

template <typename T>
void print(const T& value, const char* end) {
    std::cout << value << end;
}

template <typename T>
void print(const T& value, const T& endValue) {
    std::cout << value << endValue;
}

template <typename T, typename... Args>
void print(const T& first, const Args&... rest) {
    std::cout << first;
    ((std::cout << ' ' << rest), ...);
}

std::string input(const std::string& prompt = "");

template <typename T>
T input(const std::string& prompt, const T& defaultValue) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    if (value.empty()) {
        return defaultValue;
    }
    if constexpr (std::is_same_v<T, std::string>) {
        return value;
    } else {
        std::istringstream iss(value);
        T result;
        iss >> result;
        return result;
    }
}

template <typename T>
T input(const std::string& prompt) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    if constexpr (std::is_same_v<T, std::string>) {
        return value;
    } else {
        std::istringstream iss(value);
        T result;
        iss >> result;
        return result;
    }
}

std::size_t len(const std::string& text);
template <typename T>
std::size_t len(const std::vector<T>& values) {
    return values.size();
}

std::vector<int> range(int end);
std::vector<int> range(int start, int end);
std::vector<int> range(int start, int end, int step);

#endif
