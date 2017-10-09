#include "xorshift.h"
#include <iostream>
xorshift::xorshift()
{
    //ctor
}

xorshift::~xorshift()
{
    //dtor
}


uint64_t xorshift::get(void) {
	const uint64_t s0 = s[p];
	uint64_t s1 = s[p = (p + 1) & 15];
	s1 ^= s1 << 31; // a
	s[p] = s1 ^ s0 ^ (s1 >> 11) ^ (s0 >> 30); // b,c
	return s[p] * UINT64_C(1181783497276652981);
}

void xorshift::init_seed(int32_t seed_init)
{
    seed = seed_init;
    p = seed % 16;
    for (int i = 0; i < 16; ++i)
    {
        seed = (a * seed) + c;
        s[i] = seed;
    }
}

uint64_t xorshift::get_max( uint64_t m)
{
//    std::cerr << m << "\n";
    uint64_t r;
    while ((r = get()) > UINT64_MAX - UINT64_MAX % m) {};
    return r % m;
}

double xorshift::get_real()
{
    return (double)get() / UINT64_MAX;
}
