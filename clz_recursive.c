#include "clzlib.h"

static const int mask_u8[] =  { 0, 2 };
static const int mask_u16[] =  { 0, 4, 6 };
static const int mask_u32[] =  { 0, 8, 12, 14 };
static const int mask_u64[] =  { 0, 16, 24, 28, 30 };
static const int magic[] = { 2, 1,  0, 0 };

unsigned clz2_u8(uint8_t x, int c)
{
    if (!x && !c) return 8;

    uint8_t upper = (x >> (4 >> c));
    uint8_t lower = (x & (0xF >> mask_u8[c]));
    if (c == 1) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz2_u8(upper, c + 1) : (4 >> (c)) + clz2_u8(lower, c + 1);
}

unsigned clz2_u16(uint16_t x, int c)
{
    if (!x && !c) return 16;

    uint16_t upper = (x >> (8 >> c));
    uint16_t lower = (x & (0xFF >> mask_u16[c]));
    if (c == 2) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz2_u16(upper, c + 1) : (8 >> (c)) + clz2_u16(lower, c + 1);
}

unsigned clz2_u32(uint32_t x, int c)
{
    if (!x && !c) return 32;

    uint32_t upper = (x >> (16 >> c));
    uint32_t lower = (x & (0xFFFF >> mask_u32[c]));
    if (c == 3) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz2_u32(upper, c + 1) : (16 >> (c)) + clz2_u32(lower, c + 1);
}

unsigned clz2_u64(uint64_t x, int c)
{
    if (!x && !c) return 64;

    uint64_t upper = (x >> (32 >> c));
    uint64_t lower = (x & (0xFFFFFFFF >> mask_u64[c]));
    if (c == 4) return upper ? magic[upper] : 2 + magic[lower];
    return upper ? clz2_u64(upper, c + 1) : (32 >> (c)) + clz2_u64(lower, c + 1);
}
