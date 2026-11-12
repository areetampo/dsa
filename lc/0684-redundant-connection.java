class Solution {
    public int[] findRedundantConnection(int[][] edges) {
      int[] par = new int[edges.length+1];
      int[] rank = new int[edges.length+1];
      for (int i = 0; i <= edges.length; i++) par[i] = i;

      int[] ans = new int[2];
      for (int i = 0; i < edges.length; i++) {
        int par1 = findPar(edges[i][0], par), par2 = findPar(edges[i][1], par);
        if (par1 == par2) {
          ans[0] = edges[i][0]; ans[1] = edges[i][1];
        }
        else union(par1, par2, rank, par);
      }

      return ans;
    }
    private int findPar(int x, int[] par) {
      if (x == par[x]) return x;
      return par[x] = findPar(par[x], par);
    }
    private void union(int parX, int parY, int[] rank, int[] par) {
      if (rank[parX] == rank[parY]) {
        par[parY] = parX;
        rank[parX]++;
      }
      else if (rank[parX] > rank[parY]) {
        par[parY] = parX;
      }
      else par[parX] = parY;
    }
}