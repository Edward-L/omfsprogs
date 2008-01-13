#ifndef _CONFIG_H
#define _CONFIG_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

#if 0
#define swap_be64(a) (a)
#define swap_be32(a) (a)
#define swap_be16(a) (a)
#else
#define swap_be64(a) swap64(a)
#define swap_be32(a) swap32(a)
#define swap_be16(a) swap16(a)
#endif

static inline u16 swap16(u16 a)
{
	return (((a & 0xff00) >> 8) | 
	        ((a & 0x00ff) << 8));
}

static inline u32 swap32(u32 a)
{
	return (((a & 0xff000000U) >> 24) | 
	        ((a & 0x00ff0000U) >> 8) | 
	        ((a & 0x0000ff00U) << 8) | 
	        ((a & 0x000000ffU) << 24));
}

static inline u64 swap64(u64 a)
{
	return (((a & 0xff00000000000000ULL) >> 56) |
		((a & 0x00ff000000000000ULL) >> 40) |
		((a & 0x0000ff0000000000ULL) >> 24) |
		((a & 0x000000ff00000000ULL) >> 8)  |
		((a & 0x00000000ff000000ULL) << 8)  |
		((a & 0x0000000000ff0000ULL) << 24) |
		((a & 0x000000000000ff00ULL) << 40) |
		((a & 0x00000000000000ffULL) << 56));
}


#endif /* _CONFIG_H */
