class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] a) {
        Arrays.sort(a);
        a[0] = 1;
        for (int i = 1; i < a.length; ++i) {
            if (a[i] - a[i-1] > 1) a[i] = 1 + a[i-1];
        }
        return a[a.length-1];
    }
}