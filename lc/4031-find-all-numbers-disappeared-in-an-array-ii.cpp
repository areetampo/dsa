class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& v, int l, int u) {
        int n = v.size();
        sort(v.begin(), v.end());
        int lb = lower_bound(v.begin(), v.end(), l) - v.begin();
        vector<vector<int>> r;

        if (lb == n) {
            r.push_back({l, u});
            return r;
        }

        // [1, 3, 5, 8, 9] 
        // l = 3 lb = 3
        // l = 4 lb = 5
        int i = lb;
        if (v[i] > l) r.push_back({l, min(u, v[i] - 1)}); 
        for (; i + 1 < n && v[i + 1] <= u; i++)
            if (v[i + 1] - v[i] > 1) 
                r.push_back({v[i] + 1, v[i + 1] - 1});
        if (v[i] < u) r.push_back({v[i] + 1, u});

        return r;

    }
};