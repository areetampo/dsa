class Solution {
    public int longestString(int x, int y, int z) {
        if (x == y) return 2 * (z + (2 * Math.min(x, y)));
        return 2 * (z + (2 * Math.min(x, y) + 1));
    }
}