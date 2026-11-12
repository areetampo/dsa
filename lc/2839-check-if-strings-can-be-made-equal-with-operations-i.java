class Solution {
    public boolean canBeEqual(String s1, String s2) {
        StringBuilder sb1 = new StringBuilder(s1);
        StringBuilder sb2 = new StringBuilder(s2);
        
        if (sb1.toString().equals(sb2.toString())) return true;
        
        char second = sb1.charAt(2);
        sb1.setCharAt(2, sb1.charAt(0));
        sb1.setCharAt(0, second);
        if (sb1.toString().equals(sb2.toString())) return true;
        second = sb1.charAt(2);
        sb1.setCharAt(2, sb1.charAt(0));
        sb1.setCharAt(0, second);
        
        second = sb1.charAt(3);
        sb1.setCharAt(3, sb1.charAt(1));
        sb1.setCharAt(1, second);
        if (sb1.toString().equals(sb2.toString())) return true;
        
        second = sb1.charAt(2);
        sb1.setCharAt(2, sb1.charAt(0));
        sb1.setCharAt(0, second);
        if (sb1.toString().equals(sb2.toString())) return true;
        
        return false;
    }
}