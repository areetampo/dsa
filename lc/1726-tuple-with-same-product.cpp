class Solution {
public:
    int tupleSameProduct(vector<int>& v) {
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                m[v[i] * v[j]]++;
            }
        }
        int res = 0;
        for (auto&i : m) {
            auto [k, v] = i;
            res += v * (v - 1) / 2;
        }
        return res * 8;
    }
};