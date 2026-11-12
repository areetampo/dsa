class Solution {
    public String reverseWords(String s) {
        char[] str = s.toCharArray();

        for (int i = 0; i < str.length; i++) {
            int j = i;
            while (i < str.length && str[i] != ' ') {
                i++;
            }
            reverseWord(str, j, i-1);
        }

        return new String(str);
    }
    private void reverseWord(char[] str, int s, int e) {
        while (s < e) {
            char ch = str[s];
            str[s] = str[e];
            str[e] = ch;
            s++;
            e--;
        }
    }
}