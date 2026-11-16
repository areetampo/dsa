class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {//detect cycle in directed graph using BFS
        //build graph 
        ArrayList<Integer>[] adj = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < prerequisites.length; i++) adj[prerequisites[i][1]].add(prerequisites[i][0]);

        //get indegree of all nodes
        int[] indegree = new int[numCourses];
        for (int i = 0; i < prerequisites.length; i++)
        indegree[prerequisites[i][0]]++;

        //create q and 0 indegree nodes in it
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++)
        if (indegree[i] == 0) q.add(i);

        //counter to keep track of how many nodes visited until q gets empty
        int count = 0;

        //kahn's indegree bfs
        while (!q.isEmpty()) {
            int peek = q.remove();
            count++;
            for (int neighbor : adj[peek]) {
                if (--indegree[neighbor] == 0) q.add(neighbor);
            }
        }

        //in end if all courses had indegree = 0 made at some point so added in q and count++ when removed means no cycle exists
        return count == numCourses;

    }
}