xoroshirojs is a nodejs addon for http://xorshift.di.unimi.it/xoroshiro128plus.c. For more information see http://xorshift.di.unimi.it/. It's currently only tested on linux.

# Usage

To seed the PRNG, we need a 64 bit unsigned integer. JS does not have a safe native 64 bit unsigned integer so instead we give 2 32 bit unsigned integers `xoroshirojs.seed(10, 11)`. Once seeded, use `val result = xoroshirojs.next()` to get an array of 2 32 bit unsigned integers since, again, xoroshirojs returns a 64 bit value.

# Thanks

Thanks to Sebastiano Vigna for splitmix64
Thanks to David Blackman and Sebastiano Vigna for xoroshiro128plus
