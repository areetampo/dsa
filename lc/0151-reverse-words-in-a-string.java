class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        StringBuilder word = new StringBuilder();

        for (int i = s.length()-1; i >= 0; i--) {
            while (i >= 0 && s.charAt(i) == ' ') i--;
            while (i >= 0 && s.charAt(i) != ' ') {
                word.append(s.charAt(i)); i--;
            }
            ans.append(word.reverse());
            if (word.length() != 0) ans.append(' ');
            word.setLength(0);
        }
        
        return ans.toString().substring(0, ans.length()-1);
    }
}