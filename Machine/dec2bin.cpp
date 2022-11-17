#include <iostream>
#include <string>
#include <bitset>

using std::string;

string dec2bin_u(unsigned int t) {
    if (0 == t) return "0";

    string ret;

    while (t != 0) {
        ret += (t % 2 != 0 ? '1' : '0');

        t /= 2;
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

string dec2bin(int t) {
    if (t < 0) {

        // negetive
        t = 0 - t;

        t = ~t + 1;
    }

    return dec2bin_u((unsigned int)t);
}

// recurse method, use call stack
void dec2bin_r(unsigned int t) {
    if (t / 2 != 0)
        dec2bin_r(t / 2);

    std::cout << (t % 2 == 0 ? '0' : '1') ;
}

int main() {
    dec2bin_r(164);
    std::cout << std::endl;


    std::cout << dec2bin_u(165) << std::endl;

    std::cout << dec2bin(166) << std::endl;
    std::cout << dec2bin(-166) << std::endl;

    std::cout << std::bitset<32>(-166) << std::endl;
}