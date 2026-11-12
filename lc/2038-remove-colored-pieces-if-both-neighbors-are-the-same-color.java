class Solution {
    public boolean winnerOfGame(String colors) {
        int removableA = 0;
        int removableB = 0;

        for (int i = 1; i < colors.length()-1; i++) {
            if (colors.charAt(i-1) == 'A' && colors.charAt(i) == 'A' && colors.charAt(i+1) == 'A') {
                removableA++;
            }
            if (colors.charAt(i-1) == 'B' && colors.charAt(i) == 'B' && colors.charAt(i+1) == 'B') {
                removableB++;
            }
        }

        if (removableA > removableB) return true;//bob can't make next turn since removableB's will be over earlier
        //if == -> they take turns removing and in end alice can't make next turn since she started first so bob wins
        return false;// or alice can't make next turn since removableA's will be over earlier when < condition
    }
}