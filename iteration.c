#include "clz.h"

inline __attribute((always_inline))
unsigned clz_u8(uint8_t x)
{
    int n = 8, c = 4;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

inline __attribute((always_inline))
unsigned clz_u16(uint16_t x)
{
    int n = 16, c = 8;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

inline __attribute((always_inline))
unsigned clz_u32(uint32_t x)
{
    int n = 32, c = 16;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}

inline __attribute((always_inline))
unsigned clz_u64(uint64_t x)
{
    int n = 64, c = 32;
    do {
        uint32_t y = x >> c;
        if (y) {
            n -= c;
            x = y;
        }
        c >>= 1;
    } while (c);
    return (n - x);
}
