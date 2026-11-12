class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        vector<int> f(k, 0);
        for (int &i : v) f[((i % k) + k) % k]++;
        for (int i = 1; i < k; i++) if (f[i] != f[k - i]) return 0;
        return f[0] % 2 == 0;
    }
};