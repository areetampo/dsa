class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int v[] = new int[n - (j - i + 1)];
                int idx = 0;
                for (int k = 0; k < i; ++k) v[idx++] = nums[k];
                for (int k = j+1; k < n; ++k) v[idx++] = nums[k];
                boolean inc = true;
                for (int k = 0; k < v.length-1; ++k) {
                    if (v[k+1] <= v[k]) {
                        inc = false;
                        break;
                    }
                }
                if (inc) ++ans;
            }
        }
        return ans;
    }
}