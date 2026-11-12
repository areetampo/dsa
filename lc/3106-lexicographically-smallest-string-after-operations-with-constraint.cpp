class Solution {
public:
    string getSmallestString(string s, int k) {
        string res;
        int n = s.length();
        for (int i = 0;i < n; ++i) {
            char c = s[i];
            int val = c - 'a';
            int gap = (val >= 13) ? 26 - val : val;
            // cout << c << " " << gap  << " " << k<< endl;
            if (!k) {
                res += c;
                continue;
            }
            if (gap <= k) {
                res += 'a';
                k -= gap;
            }
            else {
                c = min(c + k, c - k);
                res += c;
                k = 0;
            }
        }
        return res;
    }
};