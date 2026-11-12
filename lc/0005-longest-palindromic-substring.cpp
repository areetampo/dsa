class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (s[i] == s[j]) ++j;
            int left = i - 1, right = j;
            while (0 <= left && right < n && s[left] == s[right]) {
                --left; ++right;
            }
            int len = right - left - 1;
            if (len > ans.length()) ans = s.substr(left + 1, len);
        }
        return ans;
    }
};