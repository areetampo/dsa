class Solution {
    public String getSmallestString(int n, int k) {
        int[] a = new int[n];
        Arrays.fill(a, 1); a[n-1] = k - (n-1);
        
        int i = n-1;
        while (a[i] > 26) {//from end as lexicographically smallest string needed
            a[i-1] += a[i] - 26;
            a[i] = 26;
            i--;
        }

        StringBuilder ans = new StringBuilder();
        for (int el : a) {
            ans.append((char) (el + 96));//a = 1 to z = 26
        }
        return ans.toString();
    }
}