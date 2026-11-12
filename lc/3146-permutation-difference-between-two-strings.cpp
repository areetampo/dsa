class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++) v[s[i] - 97] = i;
        int res = 0;
        for (int i = 0; i < t.length(); i++) res += abs(i - v[t[i] - 97]);
        return res;
    }
};