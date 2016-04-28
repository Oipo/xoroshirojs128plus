#include <stdint.h>

extern "C" {
    void xoroshiro_seed(uint64_t high, uint64_t low);
    uint64_t xoroshiro_next(void);
}
