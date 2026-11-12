class Solution {
public:
    int minZeroArray(vector<int>& a, vector<vector<int>>& q) {
        //binary search for index of queries
        //line sweep on queries until that index
        //check if all can be made 0 in arr, if can be -> reduce the queries index
        //cuz min number of queries so arr can be made 0
        if (all_of(a.begin(), a.end(), [](int& i){return i == 0;})) return 0;//edge case
        int n = a.size(), m = q.size();
        int lo = 0, hi = m - 1;
        while (lo <= hi) {
            vector<int> qq(n + 1, 0);
            int q_idx = lo + (hi - lo) / 2;
            for (int i = 0; i <= q_idx; i++) {
                int l = q[i][0], r = q[i][1], v = q[i][2];
                qq[l] += v, qq[r + 1] -= v;
            }
            bool can = 1;
            for (int i = 0, val = 0; i < n; i++) {
                val += qq[i];
                if (a[i] > val) {
                    can = 0; break;
                }
            }
            // cout << q_idx << "\n";
            // for (int& j : qq) cout << j << " "; cout << "\n" << can << "--\n";
            if (can) hi = q_idx - 1;
            else lo = q_idx + 1;
        }
        return lo == m ? -1 : lo + 1;
    }
};