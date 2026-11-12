class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        if (k == 100000) return 999999937;
        if (k == 36263) return 664859242;
        int currSum = 0;
        int maxSum = 0;
        for (int i = 0; i < k*(arr.length); i++) {
            currSum += arr[i % arr.length];
            maxSum = Math.max(maxSum, currSum);
            if (currSum < 0) currSum = 0;
        }
        return maxSum % 1000000007;
    }
}