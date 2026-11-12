class Solution {
public:
    int m = 1e9 + 7;
    long long pow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return r;
    }
    int sumDecoded(vector<long long>& nums) {
        long long r = 0;
        for (auto& i : nums) {
            long long w = i % 10, d = i / 10;
            int digits = log10(d) + 1;
            long long x = d / pow(10, digits - w),
                      y = d % pow(10, digits - w);
            cout << i << " " << x << " " << y << "\n";
            r = (r + pow(x, y)) % m;
        }
        return r;
    }
};