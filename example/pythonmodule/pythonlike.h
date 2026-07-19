#ifndef PYTHONLIKE_H
#define PYTHONLIKE_H

#include <iostream>
#include <string>
#include <sstream>

void print(const std::string& text);
void print(const std::string& text, const std::string& end);
void print(const std::string& text, const char* end);
std::string input(const std::string& prompt = "");

#endif
