class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long res = 0;
        stack<int> s;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && s.top() < nums[i]) {
                mp[s.top()]--; s.pop();
            }
            s.push(nums[i]);
            mp[nums[i]]++;
            res += mp[nums[i]];
        }
        return res;
    }
};