class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int max_diff, vector<vector<int>>& q) {
        vector<int> d; // nums[d[i - 1] + 1] to nums[d[i]] disjoint segment
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] > max_diff) 
                d.push_back(i);
        }
        d.push_back(n - 1);
        // nums = [1 2 3 4 6 7 8 9 11 12 13] max_diff = 1
        // idx     0 1 2 3 4 5 6 7 8  9  10
        // d =    [      3       7       10]
        // idx           0       1       2
        vector<bool> r;
        for (auto& i : q) {
            int u = i[0], v = i[1];
            int u_lb = lower_bound(d.begin(), d.end(), u) - d.begin(),
                v_lb = lower_bound(d.begin(), d.end(), v) - d.begin();
            r.push_back(u_lb == v_lb);
        }
        return r;
    }
};