class Solution {
    public int buyChoco(int[] prices, int money) {
        int c = prices[0], d = 101;
        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] <= c) {
                d = c; 
                c = prices[i];
            }
            else d = Math.min(d, prices[i]);
        }
        return (c > money || d > money || c + d > money) ? money : money - c - d;
    }
}