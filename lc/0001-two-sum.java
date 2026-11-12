class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hm = new HashMap<>();//key = element, val = index
        hm.put(nums[0], 0);
        int[] ans = new int[2];

        for (int i = 1; i < nums.length; i++) {
            if (hm.containsKey(target - nums[i])) {
                ans[0] = hm.get(target - nums[i]);
                ans[1] = i;//indexes to be returned
                break;
            }
            hm.put(nums[i], i);//put in hm 
        }
        
        return ans;//won't reach as answer always exists
    }
}
