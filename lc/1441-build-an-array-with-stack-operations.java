class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        int i = 0, j = 1;
        while (i < target.length) {
            if (target[i] != j) {
                ans.add("Push");
                ans.add("Pop");
                j++;
            }
            else {
                ans.add("Push");
                i++;
                j++;
            }
        }
        return ans;
    }
}