class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;//curr % k, index of appearing
        int curr = 0;
        m[0] = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            if (m.find(curr % k) != m.end()) {
                res = max(res, i - m[curr % k]);
            } else m[curr % k] = i;//always first occurece kept in map
        } 
        return res >= 2;//min len 2 needed
    }
};