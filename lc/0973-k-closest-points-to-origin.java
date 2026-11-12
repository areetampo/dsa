class Solution {
    static class Info implements Comparable<Info>{
        int x;
        int y;
        int dist;
        int idx;
        Info(int x, int y, int dist, int idx) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.idx = idx;
        }
        @Override 
        public int compareTo(Info point) {//ascending order in terms of distance
            return this.dist - point.dist;
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Info> ans = new PriorityQueue<>();
        for (int i = 0; i < points.length; i++) {
            ans.add(new Info(points[i][0], points[i][1], points[i][0]*points[i][0] + points[i][1]*points[i][1], i));
        }

        int[][] a = new int[k][2];//to store the first k points added in priorityQueue

        for (int i = 0; i < k; i++) {//k points mean 0 -> k-1
            a[i][0] = ans.peek().x;
            a[i][1] = ans.peek().y;  
            ans.remove();
        }
        return a;
    }
}