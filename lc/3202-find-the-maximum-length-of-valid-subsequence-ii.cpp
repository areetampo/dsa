class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int res = 0, n = v.size();
        for (int i = 0; i < k; i++) {
            int r = 0;
            unordered_map<int, int> m;//% k val, mx len of seq
            for (int j = 0; j < n; j++) {
                int curr = v[j] % k;
                if (m.find(i - curr) != m.end()) {
                    m[curr] = m[i - curr] + 1;
                } else if (m.find(i + k - curr) != m.end()) {
                    m[curr] = m[i + k - curr] + 1;
                } else {
                    m[curr] = 1;
                }
                r = max(r, m[curr]);
            }
            res = max(res, r);
        }
        return res;
    }
};