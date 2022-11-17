#ifndef __ENDIAN_T__
#define __ENDIAN_T__

bool isBigEndian() {
    int number = 0x1234;

    // get the low bit
    char c = * reinterpret_cast<char *>(&number);

    // return c == 0x12; wrong
    return c != 0x34;
}

#endif
