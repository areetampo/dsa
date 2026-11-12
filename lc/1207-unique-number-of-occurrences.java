class Solution {
    public boolean uniqueOccurrences(int[] a) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i : a) {
            m.put(i, m.getOrDefault(i, 0) + 1);
        }
        HashSet<Integer> s = new HashSet<>();
        for (int k : m.keySet()) {
            int v = m.get(k);
            if (s.contains(v)) return false;
            s.add(v);
        }
        return true;
    }
}