class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int ss = 0, gg = 0, ans = 0;
        while (ss < s.length && gg < g.length) {
            if (s[ss] >= g[gg]) {
                ++ans; ++ss; ++gg;
            }
            else ++ss;
        }
        return ans;
    }
}