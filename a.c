#include <stdint.h>
#include <stdio.h>
/*
#define __DECLARE_ROTATE(bits, type)                   \
    static inline type rotl##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v << c) | (v >> (bits-c));             \
    }                                                  \
                                                       \
    static inline type rotr##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v >> c) | (v << (bits-c));             \
    }

#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)

DECLARE_ROTATE(8);*/

void print_bits(int x)
{
    int i;
    for (i = 7; i >= 0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

static inline uint8_t rotl8(const uint8_t v, int c)
{
    const int mask = (8) - (1);
    print_bits(v);
    c &= mask;
    printf("mask:\n");
    print_bits(mask);
    printf("c:\n");
    print_bits(c);
    printf("-c:\n");
    print_bits(-c);
    printf("8-c:\n");
    print_bits((8 - c));
    print_bits((-c & mask));
    return (v << c) | (v >> (8 - c));
}
static inline uint8_t rotr8(const uint8_t v, int c)
{
    const int mask = (8) - (1);
    print_bits(v);
    c &= mask;
    return (v >> c) | (v << (8 - c));
};

int main()
{
    printf("main\n");
    print_bits(184);
    int res = rotl8(184, 3);
    printf("%d\n", res);
    print_bits(res);

    printf("right------\n");
    res = rotr8(184, 5);
    printf("%d\n", res);
    print_bits(res);

    return 0;
}
