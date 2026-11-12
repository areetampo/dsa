class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        int r = 0;
        for (int i : nums) {
            m.put(i, m.getOrDefault(i, 0) + 1);
            r = Math.max(r, m.get(i));
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < r; ++i) {
            ans.add(new ArrayList<>());
        }
        int R = 0;
        while (R < r) {
            for (int i : m.keySet()) {
                if (m.get(i) != 0) {
                    ans.get(R).add(i);
                }
            }
            for (int i : m.keySet()) {
                if (m.get(i) != 0)
                m.put(i, m.get(i) - 1);
            }
            ++R;
        }
        return ans;
        
    }
}