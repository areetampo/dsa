class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) return;
        for (int e = m+n-1, s = m-1; s >= 0; s--, e--) {
            nums1[e] = nums1[s];
            nums1[s] = 0;
        }
        int i = n, j = 0, idx = 0;
        while (i < m+n || j < n) {
            if (i == m+n) {
                nums1[idx++] = nums2[j++];
            }
            else if (j == n) {
                nums1[idx++] = nums1[i++];
            }
            else {
                if (nums1[i] > nums2[j]) {
                    nums1[idx++] = nums2[j++];
                }
                else {
                    nums1[idx++] = nums1[i++];
                }
            }
        }
    }
}