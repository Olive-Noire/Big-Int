#include <iostream>

#include "../Headers/Int.hpp"

int main() {

    Static_Binary_Unsigned_Int<16> a, b;

    std::cout << a << " + " << b << " = " << a+b << std::endl;
    std::cout << a << " - " << b << " = " << a-b << std::endl;
    std::cout << a << " * " << b << " = " << a*b << std::endl;
    std::cout << a << " / " << b << " = " << a/b << std::endl;
    std::cout << a << " % " << b << " = " << a%b << std::endl;

    return 0;

}

// Command : g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Int" -std=c++17 -O3 -Wall -Wextra -pedantic-errors