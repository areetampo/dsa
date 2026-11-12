class Solution {
    public int findCircleNum(int[][] isConnected) {
        //need to find disconnected componenets
        int V = isConnected.length;
        boolean[] vis = new boolean[V];
        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ans++;
                dfsUtil(i, isConnected, vis);
            }
        }
        return ans;
    }
    private static void dfsUtil(int curr, int[][] isConnected, boolean[] vis) {
        vis[curr] = true;
        for (int i = 0; i < isConnected[curr].length; i++) {
            //edge exits + unvisited + (isConnected[curr][curr] not executed as vis[curr] made true above)
            if (isConnected[curr][i] == 1 && !vis[i]) {
                dfsUtil(i, isConnected, vis);
            }
        }
    }
}
