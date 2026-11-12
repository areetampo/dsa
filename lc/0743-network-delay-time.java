class Solution {
    private class Info {
        int n;//node
        int time;//up till now
        Info(int _n, int _time) {
            n = _n;
            time = _time;
        }
    }
    public int networkDelayTime(int[][] times, int n, int k) {//dijkstra algo
        int[][] adj = new int[n+1][n+1];
        for (int i = 0; i <= n; ++i) Arrays.fill(adj[i], -1);//since 0 edge wt also exists to contribute 
        for (int e[] : times) {
            adj[e[0]][e[1]] = e[2];
        }

        boolean[] vis = new boolean[n+1];

        int[] time = new int[n+1];
        for (int i = 1; i <= n; ++i) if (i != k) time[i] = Integer.MAX_VALUE;

        PriorityQueue<Info> pq = new PriorityQueue<>((a, b) -> a.time - b.time);
        pq.add(new Info(k, 0));
        vis[k] = true;
        while (!pq.isEmpty()) {
            Info peek = pq.remove();
            vis[peek.n] = true;
            for (int i = 1; i <= n; i++) {
                if (adj[peek.n][i] != -1 && !vis[i]) {
                    time[i] = Math.min(time[i], peek.time + adj[peek.n][i]);
                    pq.add(new Info(i, peek.time + adj[peek.n][i]));
                }
            }
        }

        int ans = -1;
        for (int t : time) ans = Math.max(ans, t);
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}