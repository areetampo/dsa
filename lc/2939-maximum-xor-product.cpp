class Solution {
public:
    int mod = 1000000007;
    int maximumXorProduct(long long a, long long b, int n) {
        //for the last n bits:
        //let a be the bigger number so it will always encounter a set bit and b
        //wont while scanning left to right
        //if the first_set_bit_seen (in a) appears at >= n bit position
        //then set all bits (which are not not same in a and b) to 0 in a
        //and 1 in b at < n position bits
        long long mask = (1ll << n) - 1;
        if (a < b) swap(a, b);
        if (a == 0) return ((1ll << n) - 1) % mod;//log2(0) error
        // bitset<50> aa(a), bb(b), M(~mask);
        // cout << aa.to_string() << "\n" << bb.to_string() << "\n" << M.to_string() << "\n";
        long long am = a & ~mask, bm = b & ~mask;
        // bitset<50> AM(am), BM(bm);
        // cout << AM.to_string() << "\n" << BM.to_string() << "\n";
        bool first_set_bit_seen = am > bm;
        // cout << first_set_bit_seen << "\n";
        for (int i = n - 1; i >= 0; i--) {
            auto a_bit = a & (1ll << i), b_bit = b & (1ll << i);
            // cout << i << " " << a_bit << "," << b_bit << "\n";
            if (a_bit == b_bit) {
                a |= 1ll << i, b |= 1ll << i;
            } else {
                if (!first_set_bit_seen) {//a_bit = 1, b_bit = 0
                    first_set_bit_seen = 1;
                } else {
                    a &= ~(1ll << i);
                    b |= 1ll << i;
                }
            }
        }
        // cout << aa.to_string() << "\n" << bb.to_string() << "\n";
        // bitset<50> A(a), B(b);
        // cout << a << " " << b << "\n" << A.to_string() << "\n" << B.to_string();
        return ((a % mod) * (b % mod)) % mod;
    }
};