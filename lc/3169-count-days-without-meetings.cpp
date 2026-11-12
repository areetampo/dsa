class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(), m.end());
        int n = m.size(), res = m[0][0] - 1;
        for (int i = 0; i < n; i++) {
            int mx = m[i][1];
            while (i + 1 < n && m[i + 1][0] <= mx) {
                mx = max(mx, m[i + 1][1]);
                i++;
            }
            // cout << i << " " << mx << " ";
            if (i == n - 1) {
                res += days - mx;
                // cout << days - mx << ".\n";
            }
            else {
                res += m[i + 1][0] - mx - 1;
                // cout << m[i + 1][0] - mx - 1 << "\n";
            }
        }
        return res;
    }
};