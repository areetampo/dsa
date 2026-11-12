class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[][] adj = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = Math.abs(points[i][0]-points[j][0]) + Math.abs(points[i][1]-points[j][1]);
            }
        }
        int ans = 0;
        //prim's algo
        boolean[] vis = new boolean[n];
        int cnt = 0;
        PriorityQueue<Info> pq = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        pq.add(new Info(0, 0));
        while (!pq.isEmpty()) {
            Info peek = pq.remove();
            if (!vis[peek.v]) {
                vis[peek.v] = true;
                ans += peek.dist;
                if (++cnt == n) break;
            }
            for (int j = 0; j < n; ++j) {//dist to every point from every point does exist
                if (!vis[j]) pq.add(new Info(j, adj[peek.v][j]));
            }
        }
        return ans;
    }
    private static class Info {
        int v; int dist;//vertex, peek <--dist--> vertex
        Info(int _v, int _dist) {
            v = _v; dist = _dist;
        }
    }
}