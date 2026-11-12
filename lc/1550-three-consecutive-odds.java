class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int cnt = 0;
        for (int i : arr) {
            cnt = i % 2 == 1 ? cnt + 1 : 0;
            if (cnt == 3) return true;
        }
        return false;
    }
}