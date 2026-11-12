class Solution {
public:
    int countGoodRotations(vector<int>& v) {
        int n = v.size(); // even
        auto l = accumulate(v.begin(), v.begin() + n / 2, 0ll),
            r = accumulate(v.begin() + n / 2, v.end(), 0ll);

        int res = l > r;

        for (int i = 0; i < n - 1; i++) {
            l += - v[i] + v[(i + n / 2) % n],
            r += - v[(i + n / 2) % n] + v[i];
            res += l > r;
        }

        return res;
    }
};