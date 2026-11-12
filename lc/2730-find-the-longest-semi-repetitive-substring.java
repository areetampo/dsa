class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        if (s.length() == 1) return 1;
        
        int ans = 0;
        
        for (int i = 0; i < s.length()-1; ++i) {
            int duplicates = 0;
            int j = i;
            for (; j < s.length()-1; ++j) {
                if (s.charAt(j) == s.charAt(j+1)) {
                    if (duplicates == 1) {
                        break;
                    }
                    else duplicates++;
                }
                
            }
            ans = Math.max(ans, j-i+1);
        }
        return ans;
    }
}