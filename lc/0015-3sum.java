class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        // HashSet<List<Integer>> hs = new HashSet<>();
        
        int j = -1; int k = -1;
        for (int i = 0; i < n; i++) {
            j = i+1; k = n-1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;//
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k])));
                    j++; k--;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[j] + nums[k] + nums[i] > 0) k--;
                else j++;
            }
        }
        // ans.addAll(hs); 
        return ans;
    }
}