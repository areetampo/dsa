class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 0;
        while (i < nums.size() - 1 && nums[i] + 1 == nums[++i]) {
            sum += nums[i];
        }
        unordered_set<int> s;
        for (int &i : nums) s.insert(i);
        while (s.find(sum++) != s.end()){}
        return sum - 1;
    }
};