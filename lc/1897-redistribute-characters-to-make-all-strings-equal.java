class Solution {
    public boolean makeEqual(String[] words) {
        int[] freq = new int[26];
        for (String word : words) {
            for (int i = 0; i < word.length(); ++i) {
                ++freq[word.charAt(i) - 'a'];
            }
        }
        int n = words.length;
        for (int i : freq) {
            if (i % n != 0) return false;
        }
        return true;
    }
}