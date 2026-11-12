class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string r = "";

        for (int i = 0; i < n; i++) {
            string cur;
            int ones = 0;

            for (int j = i; j < n && ones < k; j++) {
                cur += s[j];
                ones += s[j] == '1';
            }

            if (ones == k) {
                if (r.empty() ||
                    cur.size() < r.size() ||
                    (cur.size() == r.size() && cur < r)) {
                    r = cur;
                }
            }
        }

        return r;
    }
};