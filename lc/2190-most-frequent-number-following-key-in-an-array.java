class Solution {
    public int mostFrequent(int[] nums, int key) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] == key) 
            hm.put(nums[i+1], hm.getOrDefault(nums[i+1], 0) + 1);
        }
        int maxFreq = -1;
        int ans = -1;
        for (int keys : hm.keySet()) {
            if (hm.get(keys) > maxFreq) {
                maxFreq = hm.get(keys);
                ans = keys;
            }
        }
        return ans;
    }
}