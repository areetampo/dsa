class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        if (n == 1) return 0;

        int score = 0;
        for (int i = 1; i < n; i++) score += s[i - 1] == s[i];

        int r = score == k;

        for (int i = 1, prev = s[0] == s[n - 1]; i < n; i++) {
            score -= (s[i - 1] == s[i]) - prev;
            r += score == k;
            prev = s[i - 1] == s[i];
        }
        
        return r;
    }
};