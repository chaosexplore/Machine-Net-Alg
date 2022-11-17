#include <iostream>

#include "endian.hpp"

int main() {
    std::cout << (isBigEndian() ? "Big Endian" : "Little Endian") << std::endl;

    int a = 0x1234;
    char b = *reinterpret_cast<char*>(&a);

    std::cout << "size of a : " << sizeof(a) << std::endl;
    std::cout << "size of b : " << sizeof(b) << std::endl;

    std::cout << "value of b : 0x" << std::hex << (int)b << std::endl;
    std::cout << "a : 0x" << a << std::endl;

    return 0;
}


