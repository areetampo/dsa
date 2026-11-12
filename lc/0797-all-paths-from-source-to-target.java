class Solution {
    static List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {//src = 0, dest = n-1
        ans = new ArrayList<>();
        Stack<Integer> s = new Stack<>();//store the path in a stack
        s.push(0);//add 0 initially as it's the src and shouldn't be removed

        for (int i = 0; i < graph[0].length; i++) {//going to all neighbours of node 0 
            path(graph, graph[0][i], s);
        }
        return ans;
    }

    public static void path(int[][] graph, int curr, Stack<Integer> s) {
        //if destination node reached
        if (curr == graph.length-1) {
            s.push(graph.length-1);//push the dest node in stack
            List<Integer> onePath = new ArrayList<>(s);//copy stack to arraylist (does it stack bottom to top which is src to dest)
            ans.add(onePath);//add the NEWLY CREATED LIST TO ans (dont use same static list and clear() as it clears from ans also)
            s.pop();//remove the dest node as now backtracks to go into new path
        }

        //go to all neighbours of curr node
        for (int i = 0; i < graph[curr].length; i++) {
            s.push(curr);//push it in stack as its part of the current path
            path(graph, graph[curr][i], s);//dfs
            s.pop();//backtracked and remove current node from path (stack) to go to next neighbour node or simply backtrack again
        }
    }
}