class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        int n = moveFrom.length;
        
        HashSet<Integer> hs = new HashSet<>();
        
        for (int el : nums) {
            hs.add(el);
        }
        
        for (int i = 0; i < n; i++) {
            hs.remove(moveFrom[i]);
            hs.add(moveTo[i]);
        }
        
        List<Integer> ans = new ArrayList<>(hs);
        
        Collections.sort(ans);
        return ans;
    }
}