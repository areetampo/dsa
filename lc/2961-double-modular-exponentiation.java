class Solution {
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < variables.length; ++i) if (calc(variables[i]) == target) ans.add(i);
        return ans;
    }
    private static int calc(int[] v) {
        int a = v[0], b = v[1], c = v[2], m = v[3];
        int e = binExp(a, b, 10);
        int ans = binExp(e, c, m);
        return ans;
    }
    private static int binExp(int x, int n, int m) {
        int ans = 1;
        while (n-- != 0) {
            ans = (ans * x) % m;
        }
        return ans;
    }
}