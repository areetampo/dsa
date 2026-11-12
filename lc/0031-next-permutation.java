class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        if (n == 1) return;

        int pivot = n-1;
        while (pivot > 0 && nums[pivot-1] >= nums[pivot]) pivot--;
        if (pivot == 0) {
            Arrays.sort(nums); return;
        }

        pivot = pivot-1;
        int e = n-1;
        while (pivot < e && nums[pivot] >= nums[e]) e--;

        int t = nums[pivot];
        nums[pivot] = nums[e];
        nums[e] = t;

        Arrays.sort(nums, pivot+1, n);

    }
}