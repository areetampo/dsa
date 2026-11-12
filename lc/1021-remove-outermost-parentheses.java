class Solution {
    public String removeOuterParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') st.push(i);
            else if (st.size() == 1) {
                int idx = st.pop();
                s = s.substring(0, idx) + s.substring(idx+1, i) + s.substring(i+1);
                i -= 2; 
            }
            else st.pop();
        }
        return s;
    }
}