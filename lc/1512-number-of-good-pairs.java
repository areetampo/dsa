class Solution {
    public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        
        for (int el : nums) {
            freq.put(el, freq.getOrDefault(el, 0) + 1);
        }

        int ans = 0;

        int val = -1;
        for (int key : freq.keySet()) {
            val = freq.get(key);
            if (val > 1) {
                ans += (val * (val - 1)) / 2; 
            }
        }

        return ans;
    }
}