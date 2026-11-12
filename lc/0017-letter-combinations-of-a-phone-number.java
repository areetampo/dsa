class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return new ArrayList<>();
        List<String> ans = new ArrayList<>();
        String[] key = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};//via indexes 2->abc ...
        f(digits, 0, new StringBuilder(), key, ans);
        return ans;
    }
    public static void f(String digits, int i, StringBuilder sb, String[] key, List<String> ans) {
        if (i == digits.length()) {
            ans.add(sb.toString()); return;
        }
        int idx = digits.charAt(i) - '0';//unicode -> corresponds to index in key[] representing digits string's current char
        for (int j = 0; j < key[idx].length(); j++) {
            f(digits, i+1, new StringBuilder(sb).append(key[idx].charAt(j)), key, ans);//append and dfs on all possible char combos
        }
    }
}