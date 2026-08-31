#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

// 这里需要注意，由于是无符号数字向右移动，因此会自动补0，没必要用一个mask再变成0了
void lfsr_calculate(uint16_t *reg) {
    
    uint16_t p0 = ((*reg)>>0)&1u;
    uint16_t p2 = ((*reg)>>2)&1u;
    uint16_t p3 = ((*reg)>>3)&1u;
    uint16_t p5 = ((*reg)>>5)&1u;
    uint16_t new = p0^p2^p3^p5;
    *reg = (*reg)>>1u;
    // uint16_t mask = ~(1u<<15);
    new = new<<15;
    // *reg = mask&(*reg);
    *reg = new|(*reg);

}

