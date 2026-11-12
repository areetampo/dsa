class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.size(), a = 0, b = 0, c = 0;
        for (int i = 0, j = 0; j < n; j++) {
            a += s[j] == 'a', b += s[j] == 'b', c += s[j] == 'c';
            while (a >= 1 && b >= 1 && c >= 1) {
                res += n - j;
                a -= s[i] == 'a', b -= s[i] == 'b', c -= s[i] == 'c';
                i++;
            }
        }
        return res;
    }
};