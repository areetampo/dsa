class Solution {
    public int minOperations(String s) {
        int currChanges1 = 0;//start from 0
        int currChanges2 = 0;//start from 1
        for (int i = 0; i < s.length(); ++i) {
            if (i % 2 == 0 && s.charAt(i) != '0' || i % 2 == 1 && s.charAt(i) != '1') ++currChanges1;
            if (i % 2 == 1 && s.charAt(i) != '0' || i % 2 == 0 && s.charAt(i) != '1') ++currChanges2;
        }
        return Math.min(currChanges1, currChanges2);
    }
}