class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {//finding topological sort
        //if cycle is present
        if (cycle(numCourses, prerequisites)) return new int[0];

        //main code for DAG 
        int[] ans = new int[numCourses]; int idx = 0;

        //BFS - Queue - Kahn's Algo
        // int[] indegree = new int[numCourses];//filled with 0 initially
        // for (int i = 0; i < prerequisites.length; i++) 
        // indegree[prerequisites[i][0]]++;//calc indegree of all nodes

        // Queue<Integer> q = new LinkedList();//adding 0s to q initially
        // for (int i = 0; i < indegree.length; i++)
        // if (indegree[i] == 0) q.add(i);

        // while (!q.isEmpty()) {
        //     int curr = q.remove();
        //     for (int i = 0; i < prerequisites.length; i++) {
        //         if (prerequisites[i][1] == curr) {
        //             int e = prerequisites[i][0];
        //             if (--indegree[e] == 0) q.add(e);//decreasing indegree of curr's neighbours + adding in q if indegree == 0
        //         }
        //     }
        //     ans[idx++] = curr;//q peeks with 0 indegree nodes added to ans in topological order
        // } 

        // return ans;

        //DFS - Stack
        boolean[] visit = new boolean[numCourses];
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) 
            topologicalSort(prerequisites, i, visit, s);//util func
        }
        while (!s.isEmpty()) ans[idx++] = s.pop();
        return ans;        
    }
    public static void topologicalSort(int[][] prerequisites, int curr,boolean[] visit, Stack<Integer> s) {
        visit[curr] = true;
        for (int i = 0; i < prerequisites.length; i++) {
            if (prerequisites[i][1] == curr) {
                if (!visit[prerequisites[i][0]]) {//unvisted neighbours
                    topologicalSort(prerequisites, prerequisites[i][0], visit, s);
                }
            }
        }
        s.push(curr);//backtrack and push in stack so highest dependency nodes present in end of stack and when popped, in end of ans
    }

    public static boolean cycle(int numCourses, int[][] prerequisites) {
        boolean[] visit = new boolean[numCourses];
        boolean[] stackArr = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if (cycleUtil(prerequisites, i, visit, stackArr)) return true;
            }
        }
        return false;
    }
    public static boolean cycleUtil(int[][] prerequisites, int curr, boolean[] visit, boolean[] stackArr) {
        visit[curr] = true;
        stackArr[curr] = true;
        for (int i = 0; i < prerequisites.length; i++) {
            if (prerequisites[i][1] == curr) {
                if (!visit[prerequisites[i][0]]) {
                    if (cycleUtil(prerequisites, prerequisites[i][0], visit, stackArr)) return true;
                }
                else if (stackArr[prerequisites[i][0]]) return true;
            }
        }
        stackArr[curr] = false;
        return false;
    }
}