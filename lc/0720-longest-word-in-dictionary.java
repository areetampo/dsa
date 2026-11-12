class Solution {
    public static class Trie {
        Trie[] child = new Trie[26];
        boolean eow;
        Trie() {
            eow = false;
            for (int i = 0; i < 26; i++)
            child[i] = null;
        }
    }
    static String ans = "";
    public String longestWord(String[] words) {
        ans = "";
        Trie root = new Trie();
        Trie curr = root;
        //storing all words in Trie
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (curr.child[words[i].charAt(j) - 'a'] == null)
                curr.child[words[i].charAt(j) - 'a'] = new Trie();

                curr = curr.child[words[i].charAt(j) - 'a'];
            }
            curr.eow = true;
            curr = root;
        }
        return longest(root, new StringBuilder());
    }
    public static String longest(Trie root, StringBuilder sb) {
        for (int i = 0; i < 26; i++) {
            if (root.child[i] != null && root.child[i].eow == true) {//first condition to consolidate nullPointerException
                longest(root.child[i], (new StringBuilder(sb)).append((char) (i + 97)));
            }

            else {//child is null/false then string until there taken
                if (ans.length() < sb.length())
    // || (ans.length() == sb.length() && ans.compareTo(sb.toString()) > 0) not needed as children 0 -> 25 (+97) chars appened in sb
                ans = sb.toString();// so they stay in lexicographical order only so update only if sb.length > 
            }
        }
        
        return ans;
    }
}