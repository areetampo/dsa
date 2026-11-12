class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int s = 0, e = numbers.length-1;
        while (true) {//soln exits
            if (numbers[s] + numbers[e] == target) {
                int[] ans = new int[2];
                ans[0] = s+1; ans[1] = e+1;
                return ans;
            }
            if (numbers[s] + numbers[e] > target) e--;
            else s++;
        }
    }
}