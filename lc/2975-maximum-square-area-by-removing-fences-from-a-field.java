class Solution {
    private static int MOD = 1000000007; 
    public int maximizeSquareArea(int m, int n, int[] hf, int[] vf) {
        int h[] = new int[hf.length+2];
        int v[] = new int[vf.length+2];
        for (int i = 0; i < hf.length; ++i) {
            h[i+1] = hf[i];
        }
        for (int i = 0; i < vf.length; ++i) {
            v[i+1] = vf[i];
        }
        h[0] = v[0] = 1;
        h[h.length-1] = m;
        v[v.length-1] = n;
        Arrays.sort(v);
        Arrays.sort(h);
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < h.length-1; ++i) {
            for (int j = i+1; j < h.length; ++j) {
                hs.add(h[j] - h[i]);
            }
        }
        int mx = 0;
        for (int k = 0; k < v.length-1; ++k) {
            for (int l = k+1; l < v.length; ++l) {
                if (hs.contains(v[l] - v[k])) mx = Math.max(mx, v[l] - v[k]);
            }
        }
        
        return (mx == 0) ? -1 : (int) (((long)mx*mx) % MOD);
    }
}