class Solution {
public:
    void dfs(int i, vector<int>& v, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        dfs(i + 1, v, nums, res);
        v.pop_back();
        dfs(i + 1, v, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(0, v, nums, res);
        return res;
    }
};