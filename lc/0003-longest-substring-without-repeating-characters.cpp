class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0; vector<int> cache(256, -1);
        for (int i = 0, j = -1; i < s.length(); i++) {
            char c = s[i];
            j = max(j, cache[c]);
            res = max(res, i - j);
            cache[c] = i;
        }
        return res;
    }
};