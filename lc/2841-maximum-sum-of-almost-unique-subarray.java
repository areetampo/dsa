class Solution {
    public long maxSum(List<Integer> nums, int m, int k) {
        long ans = 0;
        long currSum = 0;
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < k; i++) {
            int el = nums.get(i);
            hm.put(el, hm.getOrDefault(el, 0) + 1);
            currSum += el;
        }
        
        if (hm.size() >= m) {
            ans = Math.max(ans, currSum);//separately done for the first k elements since remove, put oprations inside loop
        }
        
        for (int i = k; i < nums.size(); i++) {//k index (k+1 th element) start
            int remove = nums.get(i-k);
            int put = nums.get(i);
            
            hm.put(remove, hm.get(remove) - 1);
            if (hm.get(remove) == 0) hm.remove(remove);//freq = 0 so remove otherwise hinders with hm.size() >= m
            
            hm.put(put, hm.getOrDefault(put, 0) + 1);
            
            currSum = currSum - remove + put;
            
            if (hm.size() >= m) {
                ans = Math.max(ans, currSum);
            }
        }
        
        return ans;
    }
}