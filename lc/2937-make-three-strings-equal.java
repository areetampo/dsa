class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int n = Math.min(s1.length(), Math.min(s2.length(), s3.length()));
        
        // if (s1.length() < 3 && s2.length() == s3.length() && s1.length() < 3) {
        //     return (s1.equals(s2) && s2.equals(s3)) ? 0 : -1;
        // }
        
        int i = 0; 
        while (i < n && s1.charAt(i) == s2.charAt(i) && s2.charAt(i) == s3.charAt(i)) {
            ++i;
        }
        
        if (i < 1) return -1;
        return s1.length() + s2.length() + s3.length() - 3*i;
    }
}