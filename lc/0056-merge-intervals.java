class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (r1, r2) -> {
            if (r1[0] == r2[0]) return r1[1] - r2[1];
            return r1[0] - r2[0];
        });

        ArrayList<int[]> ans = new ArrayList<>();
        int i = 0;
        while (i < n) {
            int start = intervals[i][0], end = intervals[i][1];
            ++i;
            while (i < n && end >= intervals[i][0]) { 
                start = Math.min(start, intervals[i][0]);
                end = Math.max(end, intervals[i][1]);
                ++i;
            }
            int[] x = {start, end};
            ans.add(x);
        }

        int[][] Ans = new int[ans.size()][2];
        for (int j = 0; j < ans.size(); ++j) {
            Ans[j][0] = ans.get(j)[0];
            Ans[j][1] = ans.get(j)[1];
        }
        return Ans;

    }
}