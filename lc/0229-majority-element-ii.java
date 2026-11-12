class Solution {
    public List<Integer> majorityElement(int[] nums) {//Boyer-Moore Algorithm
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;

        int candid1 = Integer.MAX_VALUE, candid2 = Integer.MAX_VALUE;
        int cnt1 = 0, cnt2 = 0;
        for (int el : nums) {
            if (candid1 == el) {
                cnt1++;
            }
            else if (candid2 == el) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                candid1 = el;
                cnt1++;
            }
            else if (cnt2 == 0) {
                candid2 = el;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        
        for (int el : nums) {
            if (el == candid1) cnt1++;
            else if (el == candid2) cnt2++;
        }
        
        if (cnt1 > nums.length/3) ans.add(candid1); 
        if (cnt2 > nums.length/3) ans.add(candid2); 
        return ans;
        
    }
}