class Solution {
public:
    bool canMakeSubsequence(string  s1, string s2) {
        for (int i = 0, j = 0; i < s1.size(); i++) {
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j]) j++;
            if (j == s2.size()) return 1;
        }
        return 0;
    }
};