class Solution {
public:
    vector<int> getMaximumXor(vector<int>& v, int mx_bit) {
        //to maximize any prefix xor: do OR with 2^mx_bit - 1
        //now the last mx_bit number of bits set to 1 (which made the value maximum possible)
        //now the k that could have been xor with the prefix to achieve this?
        //eg: mx_bit = 5 so 2^mx_bit - 1 = 11111
        //let a prefix xor be 1101100101 so its ^ k = 1101111111 (last 5 bits 1 to achieve max)
        //so the res k is the last 5 bits flipped (00101 -> 11010 so prefix ^ 11010 = max possible)
        int mask = (1 << mx_bit) - 1;
        vector<int> res;
        for (int i = 0; i < v.size(); i++) res.push_back((i == 0 ? v[0] : v[i] ^= v[i - 1]) & mask ^ mask);
        reverse(res.begin(), res.end());
        return res;
    }
};