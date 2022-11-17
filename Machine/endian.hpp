#ifndef __ENDIAN_T__
#define __ENDIAN_T__

bool isBigEndian() {
    int number = 0x1234;

    // get the low bit
    char c = * reinterpret_cast<char *>(&number);

    // return c == 0x12; wrong
    return c != 0x34;
}

#define Big2Little16(A) ((( (uint16_t)(A) & 0xff00) >> 8) | ( ((uint16_t)(A) & 0x00ff) << 8))

#define Big2Little32(A) ((( (uint32_t)(A) & 0xff000000) >> 24) | \
                        (( (uint32_t)(A) & 0x00ff0000 ) >> 8) | \
                        (( (uint32_t)(A) & 0x0000ff00 ) << 8) | \
                        (( (uint32_t)(A) & 0x000000ff ) << 24))

#endif
