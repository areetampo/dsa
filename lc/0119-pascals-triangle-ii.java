class Solution {
    public List<Integer> getRow(int rowIndex) {
        // rowIndex -> 0 based indexing

        long[] term = new long[rowIndex/2 + 1];
        term[0] = 1; 
        for (int i = 1; i <= rowIndex/2; ++i) {
            term[i] = term[i-1]*(rowIndex-i+1)/(i);//calculating nCr value uptill nC(n/2)
        }

        List<Integer> ans = new ArrayList<>();

        for (long i : term) {
            ans.add((int) i);
        }
        if (rowIndex % 2 == 1) ans.add(ans.get(rowIndex/2));
        for (int i = rowIndex/2 - 1; i >= 0; --i) {
            ans.add((int) term[i]);
        }

        return ans;
    }
}