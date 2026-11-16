class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (char& c: s) cnt[c - 97]++;
        string res; 
        char odd_char = '-';
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) odd_char = i + 97;
            if (cnt[i]) res.append(cnt[i] >> 1, i + 97);
        }
        if (odd_char != '-') res += odd_char;
        res.append(res.rbegin() + (odd_char != '-'), res.rend());
        return res;
    }
};