class Solution {
    private static int MOD = 1000000007;
    private static int rev(int n) {
        int rev = 0;
        while (n != 0) {
            rev = rev*10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    public int countNicePairs(int[] nums) {
        //i + rev(j) = rev(i) + j is equivalent to
        //pair (i, j) of indices where i - rev(i) = j - rev(j)
        //now same numbers make pairs -> (group size of same numbers)C2 combinations -> sum of all groups = ans
        HashMap<Integer, Integer> hm = new HashMap<>();
        int rev = -1;
        for (int el : nums) {
            rev = rev(el);
            hm.put(el - rev, hm.getOrDefault(el - rev, 0) + 1);
        }
        int ans = 0;
        for (int key : hm.keySet()) {
            int cnt = hm.get(key);
            ans = (int) ((ans + (long)(cnt)*(cnt - 1)/2) % MOD);//nC2 value
        }
        return ans;
    }
}