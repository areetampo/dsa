class Solution {
    public int countPairs(List<Integer> nums, int target) {
        int ans = 0;
        
        Collections.sort(nums);
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            if (nums.get(s) + nums.get(e) < target) {
                ans += e - s;
                s++;
            }
            else e--;
        }
        
        return ans;
    }
}