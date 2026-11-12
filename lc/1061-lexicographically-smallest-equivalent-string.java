class Solution {
    private class DSU {
        char[] par;
        DSU() {
            par = new char[26];
            for (int i = 0; i < 26; i++) {
                par[i] = (char) (i + 'a');
            }
        } 
        char findPar(char ch) {
            if (ch == par[ch - 'a']) return ch;
            return par[ch - 'a'] = findPar(par[ch - 'a']);
        }
        void union(char parX, char parY) {
            if (parX < parY) {
                par[parY - 'a'] = parX;
            }
            else par[parX - 'a'] = parY;
        }
    }
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        DSU dsu = new DSU();

        int n = s1.length();
        char ch1 = '.';
        char ch2 = '.';
        for (int i = 0; i < n; i++) {
            ch1 = dsu.findPar(s1.charAt(i));
            ch2 = dsu.findPar(s2.charAt(i));
            dsu.union(ch1, ch2);       
        }

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < baseStr.length(); i++) {
            ans.append(dsu.findPar(baseStr.charAt(i)));
        }

        return ans.toString();
    }
}




















