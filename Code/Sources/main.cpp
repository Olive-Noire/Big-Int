#include <iostream>

#include "../Headers/StringUtils.hpp"
#include "../Headers/Tests.hpp"

int main() {

    Static_Binary_Unsigned_Int<4> b1{7}, b2{5};

    std::cout << b1-b2 << ' ' << VirtualMemorySize<1>(b1);
    std::cin.get();
    //std::cout << Sequence(b1) << "(2) - " << Sequence(b2) << "(2) = " << Sequence(b1-b2) << "(2) = " << b1 << "(10) - " << b2 << "(10) = " << b1-b2 << "(10)";
    
    D_Dynamic_SInt a{420};
    D_Dynamic_SInt b{"48879554321858363547485554545557454555445"};

    if (ToString(a+b) != "+48879554321858363547485554545557454555865") std::cout << "Addition non implemente correctement\n";
    if (ToString(a-b) != "-48879554321858363547485554545557454555025") std::cout << "Soustraction non implemente correctement\n";
    if (ToString(a*b) != "+20529412815180512689943932909134130913286900") std::cout << "Multiplication non implemente correctement\n";
    // if (ToString(b/a) != "+116379891242519913208298939394184415608") std::cout << "Division non implemente correctement\n";

    //std::cout << "Si aucun message ne s'affiche alors l'implementation est correcte !";

    return 0;

}

// Command : g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Int" -std=c++17 -O3 -Wall -Wextra -pedantic-errors