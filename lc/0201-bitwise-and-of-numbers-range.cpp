class Solution {
public:
    int rangeBitwiseAnd(int s, int e) {
        int d = e - s;
        if (d == 0) return s;
        int bits = log2(d);
        int changes = bits == 30 ? 0 : ~((1 << (bits + 1)) - 1);
        return s & e & changes;
    }
};