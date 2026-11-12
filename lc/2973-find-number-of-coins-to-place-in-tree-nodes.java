class Solution {
    public long[] placedCoins(int[][] edges, int[] cost) {
        int n = cost.length;
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; ++i) adj[i] = new ArrayList<>();
        for (int i[] : edges) {
            adj[i[0]].add(i[1]);
            adj[i[1]].add(i[0]);
        }
        boolean[] vis = new boolean[n];
        long ans[] = new long[n];
        f(adj, -1, 0, cost, ans, vis);
        return ans;
    }
    private static List<Integer> f(ArrayList<Integer>[] adj, int par, int curr, int[] cost, long[] ans, boolean[] vis) {
        vis[curr] = true;
        if (adj[curr].size() == 1 && adj[curr].get(0) == par) {
            ans[curr] = 1;
            return Arrays.asList(cost[curr]);
        }
        List<Integer> l = new ArrayList<>();
        for (int child : adj[curr]) {
            if (child != par) l.addAll(f(adj, curr, child, cost, ans, vis));
        }
        l.add(cost[curr]);
        Collections.sort(l);
        if (l.size() > 2) {//par, 1 child = 2, has another child means > 2 means subtree size >= 3 (inclusive of self)
            ans[curr] = 
            Math.max((long)l.get(0)*l.get(1)*l.get(l.size()-1), (long)l.get(l.size()-3)*l.get(l.size()-2)*l.get(l.size()-1));
            if (ans[curr] < 0) ans[curr] = 0;
        }
        else ans[curr] = 1;
        if (l.size() > 3) {
            for (int i = 2; i < l.size() - 3; ++i) {
                l.remove(2);
            }
        } 
        return l;
    }
}