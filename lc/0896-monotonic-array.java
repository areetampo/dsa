class Solution {
    public boolean isMonotonic(int[] nums) {
        int min = nums[nums.length-1];
        int max = nums[nums.length-1];

        if (nums[0] <= nums[nums.length-1]) {//inc
            for (int i = 0; i < nums.length-1; i++) {
                min = Math.min(min, nums[i]);
                if (nums[i] > nums[i+1]) 
                return false;
            }
        } 

        else if(nums[0] >= nums[nums.length-1]) {//dec
            for (int j = 0; j < nums.length-1; j++) {
                max = Math.max(max, nums[j]);
                if (nums[j] < nums[j+1]) 
                return false;
            }
        }

        else if (min < nums[0] && nums[0] < max) return false;
        //when first element not max/min, array isn't sorted inc/dec

        return true;

    }
}