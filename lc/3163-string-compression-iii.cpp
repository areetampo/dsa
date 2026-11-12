class Solution {
public:
    string compressedString(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j + 1 < s.size() && s[j] == s[j + 1]) j++;
            int len = j - i + 1;
            while (len) res += to_string(min(len, 9)) + s[i], len -= min(len, 9);
            i = j + 1;
        }
        return res;
    }
};