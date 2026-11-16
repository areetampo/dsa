class Solution {
public:
    int minimumPushes(string s) {
        int cnt[26];
        for (char& c : s) cnt[c - 97]++;
        // 2 to 9 = 8 keys mapped
        // most used chars in s should be pressed once (top 8 freq) then next 8 pressed twice and so on ...
        sort(cnt, cnt + 26, greater<int>());
        int res = 0;
        for (int i = 0, j = 1; i < 26; i++) {
            j += i && (i % 8) == 0;
            res += cnt[i] * j;
        }
        return res;
    }
};