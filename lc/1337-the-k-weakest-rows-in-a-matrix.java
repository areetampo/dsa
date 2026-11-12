class Solution {
    public static class Row implements Comparable<Row> {
        int soldiers;
        int idx;
        Row(int soldiers, int idx) {
            this.soldiers = soldiers;
            this.idx = idx;
        }
        @Override 
        public int compareTo(Row r2) {
            if (this.soldiers == r2.soldiers) {
                return this.idx - r2.idx;//if equal soldiers in both rows then ascending order of row indexes
            }
            return this.soldiers - r2.soldiers;//sorted in ascending order of soldiers
        }
    }
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<Row> rows = new PriorityQueue<>();

        for (int i = 0; i < mat.length; i++) {
            int soldiers = 0;
            for (int j = 0; j < mat[i].length; j++) {//finding num of soldiers/row
                if (mat[i][j] == 1) 
                soldiers++;
            }
            rows.add(new Row(soldiers, i));
        }

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {//storing first k sorted in ans[]
            ans[i] = rows.remove().idx;
        }
        return ans;
    }
}