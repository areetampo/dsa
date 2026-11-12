class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int ans = 0;
        int dash = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves.charAt(i) == 'L') ans--;
            else if (moves.charAt(i) == 'R') ans++;
            else dash++;
        }
        return Math.abs(ans) + dash;

    }
}