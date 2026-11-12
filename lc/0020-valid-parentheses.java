class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        stack.push(s.charAt(0));

        for (int i = 1; i < s.length(); i++) {
            char ch = s.charAt(i);
            if ((!stack.isEmpty()) && ((ch == 41 && stack.peek() == 40) || 
            (ch == 93 && stack.peek() == 91) || (ch == 125 && stack.peek() == 123))) {
                stack.pop();
            }
            else stack.push(s.charAt(i));
        }
        
        return stack.isEmpty();
    }
}