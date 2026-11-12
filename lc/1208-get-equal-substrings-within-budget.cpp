class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, n = s.length(), res = 0;
        for (int i = 0; i < n; ++i) cout << abs(s[i] - t[i]) << " "; cout << endl;
        while (j < n) {
            maxCost -= abs(s[j] - t[j]);
            if (maxCost < 0) {
                maxCost += abs(s[i] - t[i++]);
            }
            j++;
            // res = max(res, j - i + 1);
        }
        return j - i;//len aways increasing
    }
};