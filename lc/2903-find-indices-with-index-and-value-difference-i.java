class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int[] ans = {-1,-1};
        if (indexDifference == 0 && valueDifference == 0) {
            ans[0] = 0; ans[1] = 0;
            return ans;
        }
        
        for (int i = 0; i < nums.length-1; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (Math.abs(i - j) >= indexDifference && Math.abs(nums[i] - nums[j]) >= valueDifference) {
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        
        return ans;
    }
}