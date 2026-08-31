#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
// 思路：只需要让1与指定的位置做&运算即可提取该位
unsigned get_bit(unsigned x,
                 unsigned n) {
    x = x>>n;
    unsigned temp = x&1;
    return temp;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
// 思路：先将要改变的位置变成0（其余位置不变）（用mask），然后再将目标位置与0做|
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    *x = (*x)&(~(1u<<n));
    *x = (*x)|(v<<n);
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
// 思路：用XOR运算即可（0^1 = 1, 1^1 = 0，相同是0，不同是1)
void flip_bit(unsigned * x,
              unsigned n) {
    *x = (*x)^(1u<<n);
}

