#include "clzlib.h"


static inline __attribute((always_inline))
unsigned clz_u8(uint8_t x)
{
    if (x == 0) return 8;
    int n = 1;
    if ((x >> 4) == 0) {
        n += 4;
        x <<= 4;
    }
    if ((x >> 6) == 0) {
        n += 2;
        x <<= 2;
    }
    n = n - (x >> 7);
    return n;
}
static inline __attribute((always_inline))
unsigned clz_u16(uint16_t x)
{
    if (x == 0) return 16;
    int n = 1;
    if ((x >> 8) == 0) {
        n += 8;
        x <<= 8;
    }
    if ((x >> 12) == 0) {
        n += 4;
        x <<= 4;
    }
    if ((x >> 14) == 0) {
        n += 2;
        x <<= 2;
    }
    n = n - (x >> 15);
    return n;
}
static inline __attribute((always_inline))
unsigned clz_u32(uint32_t x)
{
    if (x == 0) return 32;
    int n = 1;
    if ((x >> 16) == 0) {
        n += 16;
        x <<= 16;
    }
    if ((x >> 24) == 0) {
        n += 8;
        x <<= 8;
    }
    if ((x >> 28) == 0) {
        n += 4;
        x <<= 4;
    }
    if ((x >> 30) == 0) {
        n += 2;
        x <<= 2;
    }
    n = n - (x >> 31);
    return n;
}

static inline __attribute((always_inline))
unsigned clz_u64(uint64_t x)
{
    if (x == 0) return 64;
    int n = 1;
    if ((x >> 32) == 0) {
        n += 32;
        x <<= 32;
    }
    if ((x >> 48) == 0) {
        n += 16;
        x <<= 16;
    }
    if ((x >> 56) == 0) {
        n += 8;
        x <<= 8;
    }
    if ((x >> 60) == 0) {
        n += 4;
        x <<= 4;
    }
    if ((x >> 62) == 0) {
        n += 2;
        x <<= 2;
    }
    n = n - (x >> 63);
    return n;
}
