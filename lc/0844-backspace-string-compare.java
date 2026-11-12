class Solution {
    public boolean backspaceCompare(String s, String t) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder t1 = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '#') {
                if (s1.length() != 0) s1.deleteCharAt(s1.length()-1);
            }
            else s1.append(s.charAt(i));
        }
        for (int i = 0; i < t.length(); ++i) {
            if (t.charAt(i) == '#') {
                if (t1.length() != 0) t1.deleteCharAt(t1.length()-1);
            }
            else t1.append(t.charAt(i));
        }
        return s1.toString().equals(t1.toString());
    }
}