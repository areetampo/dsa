class Solution {
    public int countHomogenous(String s) {
        int MOD = 1000000007;
        int ans = 0;
        char ch = '/';
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            cnt = (ch == s.charAt(i)) ? cnt + 1 : 1;
            ans = (ans + cnt) % MOD;
            ch = s.charAt(i);
        }
        return ans;
    }
}