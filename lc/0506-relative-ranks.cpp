class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) v.push_back({score[i], i});
        sort(v.rbegin(), v.rend());
        vector<string> res(n);
        res[v[0].second] = "Gold Medal";
        if (n == 1) return res;
        res[v[1].second] = "Silver Medal";
        if (n == 2) return res;
        res[v[2].second] = "Bronze Medal";
        if (n == 3) return res;
        for (int i = 3; i < n; ++i) {
            res[v[i].second] = to_string(i + 1);//position = index + 1
        }
        return res;
    }
};