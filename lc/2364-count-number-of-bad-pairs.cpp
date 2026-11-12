class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        //j - i != [j] - [i]
        //[i] - i != [j] - j
        unordered_map<int, int> m;
        long long res = 0;
        for (int i = 0; i < v.size(); i++) {
            res += i - m[v[i] - i]++;
        }
        return res;
    }
};