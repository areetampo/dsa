class Solution {
public:
    int lenLongestFibSubseq(vector<int>& v) {
        set<int> s;
        int n = v.size();
        int res = 0;
        for (int i = 0; i < n; i++) s.insert(v[i]);
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a = v[i], b = v[j], r = 2;
                while (s.count(a + b)) {
                    r++;
                    int sum = a + b;
                    a = b, b = sum;
                }
                res = max(res, r);
            }
        }
        return res < 3 ? 0 : res;
    }
};