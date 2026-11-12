class Solution {
public:
    int specialArray(vector<int>& nums) {
        //x numbers in nums >= x 
        //for each element, how many greater than or equal to it ->
        //if (val >= freq) -> return freq
        sort(nums.begin(), nums.end());
        int mx = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n - i && mx < n - i) return n - i;
            mx = max(mx, nums[i]);
        }
        return -1;
    }
};