class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        int n = nums.size();

        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int el : nums) {
            hm.put(el, hm.getOrDefault(el, 0) + 1);
        }
        
        int maxCnt = 0;
        for (Integer key : hm.keySet()) {
            maxCnt = Math.max(maxCnt, hm.get(key));
        }
        
        if (maxCnt > n/2) return maxCnt - (n - maxCnt);
        
        return (n % 2 == 0) ? 0 : 1;


    }
}