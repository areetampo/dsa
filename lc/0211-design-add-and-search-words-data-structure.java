class WordDictionary {
    private class TrieNode {    
        boolean eow;
        TrieNode[] child;
        TrieNode() {
            eow = false;
            child = new TrieNode[26];
            for (int i = 0; i < 26; i++) child[i] = null;
        }
    }

    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (curr.child[ch - 'a'] == null) {
                curr.child[ch - 'a'] = new TrieNode();
            }
            curr = curr.child[ch - 'a'];
        }
        curr.eow = true;
    }
    
    public boolean search(String word) {
        return searchUtil(word, 0, root);
    }
    private static boolean searchUtil(String word, int i, TrieNode curr) {//searching recursively due to dots
        if (i == word.length()-1) {
            if (word.charAt(i) == '.') {
                for (int k = 0; k < 26; k++) {
                    //at least 1 char req to match with '.' which is a eow 
                    if (curr.child[k] != null && curr.child[k].eow) return true;
                }
                return false;
            }
            return curr.child[word.charAt(i) - 'a'] != null && curr.child[word.charAt(i) - 'a'].eow;
            //char must be present and eow must be true
        } 
        if (word.charAt(i) == '.') {
            for (int k = 0; k < 26; k++) {
                if (curr.child[k] != null) {
                    if (searchUtil(word, i+1, curr.child[k])) return true;
                }
            }
        }
        else if (curr.child[word.charAt(i) - 'a'] != null) {
            if (searchUtil(word, i+1, curr.child[word.charAt(i) - 'a'])) return true;
        }
        return false;
    }

}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */