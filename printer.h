#pragma once

#include <iostream>


template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first;
    ((std::cout << '\t' << args), ...);
    std::cout << std::endl;
}

template <typename T, typename... Args>
void printInt(T first, Args... args) {
    std::cout << (int)first;
    ((std::cout << '\t' << (int)args), ...);
    std::cout << std::endl;
}


template <typename T>
void printBinary(typename T num) {
    int numBits = sizeof(T) * 8;
    T mask = static_cast<T>(1) << (numBits - 1);
    for (int i = 0; i < numBits; ++i) {
        std::cout << ((num & mask) ? '1' : '0');
        mask = mask >> 1;
    }
    std::cout << "\t";
}