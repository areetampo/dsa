class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int n = nums.size();
        
        int i = 0;
        for (; i < n-1; i++) {
            if (nums.get(i) > nums.get(i+1)) break;
        }
        
        if (i == n-1) return 0;
        
        for (int j = i+1; j != i; j = (j + 1) % n) {
            if (nums.get(j) > nums.get((j+1) % n)) return -1;
        }
        
        return n - (i+1);
    }
}