class Solution {
    public int countCharacters(String[] words, String chars) {
        int ch[] = new int[26];
        for (int i = 0; i < chars.length(); ++i) ch[chars.charAt(i) - 'a']++;
        int ans = 0;
        int word[] = new int[26];
        boolean match;
        for (String s : words) {
            Arrays.fill(word, 0);
            match = true;
            for (int i = 0; i < s.length(); ++i) {
                if (++word[s.charAt(i) - 'a'] > ch[s.charAt(i) - 'a']) match = false;
            }
            if (match) ans += s.length();
        }
        return ans;
    }
}