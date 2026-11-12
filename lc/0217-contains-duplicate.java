class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for (int el : nums) {
            if (hs.contains(el)) return true;
            hs.add(el);
        }
        return false;
    }
}