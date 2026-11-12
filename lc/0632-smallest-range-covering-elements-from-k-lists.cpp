class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int, int>> all; // val, its list
        for (int i = 0; i < k; i++)
            for (int& el : nums[i])
                all.push_back({el, i});
        sort(all.begin(), all.end());
        int n = all.size(), resI = 0, resJ = 1e9;
        unordered_map<int, int>
            m; // considered list, its freq (vals taken from it)
        //   dbg(all);
        for (int i = 0, j = 0; j < n; j++) {
            m[all[j].second]++;
            while (m.size() == k) {
                if (all[j].first - all[i].first < resJ - resI)
                    resI = all[i].first, resJ = all[j].first;
                if (--m[all[i].second] == 0)
                    m.erase(all[i].second);
                i++;
            }
        }
        //   dbg(resI); dbg(resJ);
        return {resI, resJ};
    }
};