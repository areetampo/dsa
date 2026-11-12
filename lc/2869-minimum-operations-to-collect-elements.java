class Solution {
    public int minOperations(List<Integer> nums, int k) {
        HashSet<Integer> hs = new HashSet<>();
        
        int count = 0;
        int K = k;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            int el = nums.get(i);
            count++;
            if (!hs.contains(el) && el <= K) {
                hs.add(el);
                k--;
            }
            if (k == 0) break;
        }
        // 3 2 5 3 1
        return count;
    }
}