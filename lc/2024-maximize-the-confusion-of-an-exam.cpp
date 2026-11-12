class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int res = 0;
        for (int i = 0, j = 0, t = 0, f = 0; j < s.size(); j++) {
            t += s[j] == 'T';
            f += s[j] == 'F';
            while (min(t, f) > k) {
                t -= s[i] == 'T';
                f -= s[i++] == 'F';
            }
            // cout << i << " " << j << " " << t << " " << f << '\n';
            res = max(res, j - i + 1);
        }
        return res;
    }
};