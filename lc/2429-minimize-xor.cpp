class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2_bits = __builtin_popcount(num2);
        //x ^ num1 smallest value
        //so with available set bit count in x (num2_bits)
        //assign those bits to the leftmost position in x which have set bit in
        //num1 as well, so xor of those result in 0 at leftmost places
        //do until num2_bits are avilable, if all exhausted before traversing
        //set bits of num1 then that means the rest of the bits in x should be 0
        //only so return
        //eg: num1 = 0100111001, num2_bits = 5
        //so x = 0100111001 -> has 5 set bits and ^ with num1 minimized
        //eg: num1 = 1001001101, num2_bits = 2
        //so x = 1001000000
        //if all num1 bits exhausted and num2_bits still remain then that means
        //num1 ^ x = 0 as of now but still some set bits req in x so assign
        //them at rightmost positions
        //eg: num1 = 11101010, num2_bits = 7
        //x = 11101010 so num1 ^ x = 0 but only 5 bits used, so assign the 2 bits
        //leftover at lsb positions -> 11101111
        int x = 0;
        for (int i = log2(num1); i >= 0 && num2_bits > 0; i--) {
            int mask = 1 << i;
            if (num1 & mask) x |= mask, num2_bits--;
        }
        for (int i = 0; num2_bits > 0; i++) {
            int mask = 1 << i;
            if ((x & mask) == 0) x |= mask, num2_bits--;
        }
        return x;
    }
};
