class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0, res = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'a') mask ^= 1;
            if (c == 'e') mask ^= 2;
            if (c == 'i') mask ^= 4;
            if (c == 'o') mask ^= 8;
            if (c == 'u') mask ^= 16;
            // same appearance again means vowels were evened out
            if (m.find(mask) != m.end()) res = max(res, i - m[mask]);
            else m[mask] = i;
        } 
        return res;
    }
};