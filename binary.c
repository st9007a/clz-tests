#include "clz.h"

inline __attribute((always_inline))
unsigned clz_u8(uint8_t x)
{
    if (x == 0) return 8;
    int n = 0;
    if (x <= 0x0F) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3F) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7F) {
        n += 1;
        x <<= 1;
    }
    return n;
}

inline __attribute((always_inline))
unsigned clz_u16(uint16_t x)
{
    if (x == 0) return 16;
    int n = 0;
    if (x <= 0x00FF) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFF) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFF) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFF) {
        n += 1;
        x <<= 1;
    }
    return n;
}

inline __attribute((always_inline))
unsigned clz_u32(uint32_t x)
{
    if (x == 0) return 32;
    int n = 0;
    if (x <= 0x0000FFFF) {
        n += 16;
        x <<= 16;
    }
    if (x <= 0x00FFFFFF) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFFFFFF) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFFFFFF) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFFFFFF) {
        n += 1;
        x <<= 1;
    }
    return n;
}

inline __attribute((always_inline))
unsigned clz_u64(uint64_t x)
{
    if (x == 0) return 64;
    int n = 0;
    if (x <= 0x00000000FFFFFFFF) {
        n += 32;
        x <<= 32;
    }
    if (x <= 0x0000FFFFFFFFFFFF) {
        n += 16;
        x <<= 16;
    }
    if (x <= 0x00FFFFFFFFFFFFFF) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFF) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFF) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFF) {
        n += 1;
        x <<= 1;
    }
    return n;
}
