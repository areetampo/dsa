class Solution {
    public int removeAlmostEqualCharacters(String word) {
        if (word.length() == 1) return 0;
        if (word.length() == 2) return (similar(word.charAt(0), word.charAt(1))) ? 1 : 0;
        StringBuilder s = new StringBuilder(word);
        int i = 1, ans = 0;
        while (i < s.length() - 1) {
            if (similar(s.charAt(i-1), s.charAt(i)) && similar(s.charAt(i), s.charAt(i+1))) {
                ++ans;
                s.setCharAt(i, (char)(((s.charAt(i) + 3) % 97) + 97));
                i += 2;
            }
            else if (similar(s.charAt(i-1), s.charAt(i))) {
                ++ans;
                ++i;
            }
            else i++;
        }
        return (similar(s.charAt(s.length() - 2), s.charAt(s.length() - 1))) ? ++ans : ans;
    }
    private static boolean similar(char a, char b) {
        return a == b || a - 1 == b || a + 1 == b;
    }
}