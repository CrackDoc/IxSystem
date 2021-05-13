

#if defined(_MSC_VER) && _MSC_VER < 1600

typedef __int8 Int8;
typedef unsigned __int8 Uint8;
typedef __int16 Int16;
typedef unsigned __int16 Uint16;
typedef __int32 Int32;
typedef unsigned __int32 Uint32;
typedef __int64 Int64;
typedef unsigned __int64 Uint64;

#else

#include <stdint.h>

typedef int8_t Int8;
typedef uint8_t Uint8;
typedef int16_t Int16;
typedef uint16_t Uint16;
typedef int32_t Int32;
typedef uint32_t Uint32;
typedef int64_t Int64;
typedef uint64_t Uint64;

#endif
