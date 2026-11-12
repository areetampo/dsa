class Solution {
    // private static class Pair {
    //     int x;
    //     int y;
    //     Pair(int x, int y) {
    //         this.x = x;
    //         this.y = y;
    //     }
    // }
    public boolean isPathCrossing(String path) {
        HashSet<Pair<Integer, Integer>> set = new HashSet<>();
        int x = 0, y = 0;
        set.add(new Pair(x, y));
        for (char ch : path.toCharArray()) {
            if (ch == 'N') ++y;
            else if (ch == 'W') --x;
            else if (ch == 'S') --y;
            else ++x;
            if (set.contains(new Pair(x, y))) return true;
            set.add(new Pair(x, y));
        }
        return false;
    }
}