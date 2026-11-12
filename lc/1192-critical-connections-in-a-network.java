class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {//tarjan bridge algo
        //convert to adjacency list;
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < connections.size(); i++) {
            //connections.get(i).get(0) <-> connections.get(i).get(1)
            adj[connections.get(i).get(0)].add(connections.get(i).get(1));
            adj[connections.get(i).get(1)].add(connections.get(i).get(0));
        }
        //ans list
        List<List<Integer>> ans = new ArrayList<>();
        //tarjan's arrays
        boolean[] vis = new boolean[n];
        int[] parent = new int[n];
        int[] dt = new int[n];//discovery time
        int[] ldt = new int[n];//lowest discovery time
        //dfs
        time = 0; parent[0] = -1;
        dfs(0, vis, parent, dt, ldt, ans, adj);
        return ans;
    }
    static int time;
    public static void dfs(int curr, boolean[] vis, int[] parent, int[] dt, int[] ldt, List<List<Integer>> ans,
    ArrayList<Integer>[] adj) {
        vis[curr] = true;
        dt[curr] = ++time; ldt[curr] = dt[curr];
        for (int neighbor : adj[curr]) {
            if (neighbor == parent[curr]) continue;
            else if (!vis[neighbor]) {
                parent[neighbor] = curr;
                dfs(neighbor, vis, parent, dt, ldt, ans, adj);
                ldt[curr] = Math.min(ldt[curr], ldt[neighbor]);
                if (dt[curr] < ldt[neighbor]) {
                    List<Integer> bridgeEdge = new ArrayList<>(); bridgeEdge.add(curr); bridgeEdge.add(neighbor);
                    ans. add(bridgeEdge);
                }
            }
            else {//neighbor visited
                ldt[curr] = Math.min(ldt[curr], dt[neighbor]);
            }
        }
    }

}