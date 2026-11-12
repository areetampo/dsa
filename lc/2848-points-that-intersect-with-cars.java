class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        HashSet<Integer> hs = new HashSet<>();
        for (List<Integer> l : nums) {
            for (int i = l.get(0); i <= l.get(1); i++) {
                hs.add(i);
            }
        }
        return hs.size();
    }
}