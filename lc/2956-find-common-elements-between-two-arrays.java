class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        HashSet<Integer> hs = new HashSet<>();
        for (int i : nums1) hs.add(i);
        int c1 = 0;
        for (int i : nums2) if (hs.contains(i)) c1++;
        hs.clear();
        for (int i : nums2) hs.add(i);
        int c2 = 0;
        for (int i : nums1) if (hs.contains(i)) c2++;
        int ans[] = {c2, c1};
        return ans;
    }
}