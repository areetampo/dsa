class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        if (purchaseAmount % 10 >= 5) {
            purchaseAmount = (purchaseAmount/10 + 1) * 10;
        }
        else if (purchaseAmount % 10 > 0) purchaseAmount = (purchaseAmount/10) * 10;
        
        return 100 - purchaseAmount;
    }
}