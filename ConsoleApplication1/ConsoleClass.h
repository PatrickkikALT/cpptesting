#pragma once
#include <iostream>

class console_class {
public:
    static console_class& instance() {
        static console_class instance;
        return instance;
    }

    void print(const std::string& message) {
        std::cout << message << '\n';
    }

    void print(const std::string& message, int amount) {
        std::cout << message << ": " << amount << '\n';
    }

private:
    console_class() = default; // Private constructor
    console_class(const console_class&) = delete;
    console_class& operator=(const console_class&) = delete;
};
inline void print(const std::string& message) {
    console_class::instance().print(message);
}

inline void print(const std::string& message, int amount) {
    for (int i = 0; i < amount ; i++) {
        console_class::instance().print(message);
    }
}