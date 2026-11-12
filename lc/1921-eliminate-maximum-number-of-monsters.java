class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int n = dist.length;
        float[] a = new float[n];
        for (int i = 0; i < n; ++i) {
            a[i] = (float)dist[i]/speed[i];
        }
        Arrays.sort(a);
        int ans = 0, i = 0;
        while (true) {
            ans++;
            i++;
            if (i == n || ans - a[i] >= 0) break;
        }
        return ans;
    }
}