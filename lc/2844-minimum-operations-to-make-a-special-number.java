class Solution {
    public int minimumOperations(String num) {
        int ans = Integer.MAX_VALUE;
        int n = num.length();

        if (n == 1) return (num.charAt(0) == '0') ? 0 : 1; 

        char end = 'x';
        
        for (int i = n-1; i > 0; i--) {
            if (num.charAt(i) == '0') {
                end = '0';
                for (int j = i-1; j >= 0; j--) {
                    if (num.charAt(j) == '0' || num.charAt(j) == '5') {
                        ans = Math.min(ans, i-j-1 + n-1-i); 
                    }
                }
            }
            if (num.charAt(i) == '5') {
                end = '5';
                for (int j = i-1; j >= 0; j--) {
                    if (num.charAt(j) == '2' || num.charAt(j) == '7') {
                        ans = Math.min(ans, i-j-1 + n-1-i); 
                    }
                }
            }
        }
        
        if (ans == Integer.MAX_VALUE) {
            if (end == '0')
            ans = n-1;//delete all except 0
            else ans = n;
        }  
        
        return ans;
        
    }
}