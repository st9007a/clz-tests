#ifndef CLZLIB_H
#define	CLZLIB_H
#include <stdint.h>

#if defined(recursive)
#define clz(x) \
	_Generic((x), \
		uint8_t: clz2_u8, \
		uint16_t: clz2_u16, \
		uint32_t: clz2_u32, \
		uint64_t: clz2_u64, \
	)(x, 0)

unsigned clz2_u8(uint8_t x, int c);
unsigned clz2_u16(uint16_t x, int c);
unsigned clz2_u32(uint32_t x, int c);
unsigned clz2_u64(uint64_t x, int c);

#else
#define clz(x) \
	_Generic((x), \
		uint8_t: clz_u8, \
		uint16_t: clz_u16, \
		uint32_t: clz_u32, \
		uint64_t: clz_u64, \
	)(x)

static inline __attribute((always_inline))
unsigned clz_u8(uint8_t x);

static inline __attribute((always_inline))
unsigned clz_u16(uint16_t x);

static inline __attribute((always_inline))
unsigned clz_u32(uint32_t x);

static inline __attribute((always_inline))
unsigned clz_u64(uint64_t x);

#endif
#endif
