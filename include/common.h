#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdint.h>
#include <config.h>

#ifdef __CHECKER__
#define FORCE	__attribute__((force))
#else
#define FORCE
#endif

#ifdef __CHECKER__
#define BITWISE	__attribute__((bitwise))
#else
#define BITWISE
#endif

#define O_BINARY 0

#define TRUE    1
#define FALSE   0

#define NOLOCK 0x0
#define LOCK 0x1

char from_hex(char ch);
char *strtolower(char *str);

typedef uint16_t BITWISE __be16; /* big endian, 16 bits */
typedef uint32_t BITWISE __be32; /* big endian, 32 bits */
typedef uint64_t BITWISE __be64; /* big endian, 64 bits */

__be32 to_be32(uint32_t x);
__be16 to_be16(uint16_t x);
__be64 to_be64(uint64_t x);

uint32_t from_be32(__be32 x);
uint16_t from_be16(__be16 x);
uint64_t from_be64(__be64 x);

#endif // UTIL_H_INCLUDED
