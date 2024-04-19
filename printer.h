#ifndef PRINT_FUNCTION_H
#define PRINT_FUNCTION_H

#include <iostream>

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}

#endif