class Solution {
    private static class Trie {
        Trie[] child = new Trie[26];
        boolean eow = false;
        int children = 0;
        Trie() {
            for (int i = 0; i < 26; i++) child[i] = null;
        }
    }
    private static void insert(Trie curr, String s) {
        for (int j = 0; j < s.length(); j++) {
            if (curr.child[s.charAt(j) - 'a'] == null) {
                curr.child[s.charAt(j) - 'a'] = new Trie();
                curr.children++;
            }
            curr = curr.child[s.charAt(j) - 'a'];
        }
        curr.eow = true;
    }
    public String longestCommonPrefix(String[] strs) {
        Trie root = new Trie();
        Trie curr = root;

        for (int i = 0; i < strs.length; i++) {//storing words in Trie
            insert(curr, strs[i]);
            curr = root;
        }

        StringBuilder ans = new StringBuilder();
        while (!curr.eow && curr.children == 1) {//check until where only 1 child exists (string until there stored in ans)
            int i = 0;
            while (i < 26 && curr.child[i] == null) i++;

            ans.append((char) (i + 97)); //common prefix letters so can take any string to append
            
            curr = curr.child[i]; //prefix letters common to all strings
        }
        return ans.toString();
    }
}