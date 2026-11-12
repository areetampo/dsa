class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // [1, n] always possible bcz i ^ i ^ i = i
        // let n = 45
        // bits = 101101
        // res > (1 << bits of n) - 1 never possible
        // res = n + (possible values in range [n + 1, (1 << bits(n)) - 1])
        // all values up till (1 << bits(n)) - 1 possible
        // total values 0 to (1 << bits(n)) - 1 = 1 << bits(n)

        // special case:
        // n = 2 not possible to make 0 or 3 (11)
        // with other n = 2^k, setting all bits 1 always possible
        // lets say 100
        // 100 ^ 010 ^ 001 = 111
        // 010 ^ 001 ^ 011 = 000
        // there has to be room for 1s to work which 2 doesnt
        
        if (n <= 2) return n; // n = 1 only possible to get xor 1
        return 1 << (32 - __builtin_clz(n));
    }
};