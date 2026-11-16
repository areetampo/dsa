class Solution {
    public int findChampion(int[][] grid) {
        //given that no cycles present (a > b and b > c then c > a is not a possibility, a > c default)
        int n = grid.length;
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; ++i) graph[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {//i stronger
                    graph[j].add(i);
                }
                else graph[i].add(j);
            }
        }
        Queue<Integer> q = new LinkedList<>();
        boolean[] visit = new boolean[n];
        topoSort(graph, 0, visit, q);
        return q.remove();
    }
    private static void topoSort(ArrayList<Integer>[] graph, int curr, boolean[] visit, Queue<Integer> q) {
        visit[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            if (!visit[graph[curr].get(i)])
                topoSort(graph, graph[curr].get(i), visit, q);
        }
        q.add(curr);
    }
}