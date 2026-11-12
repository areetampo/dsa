class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nums.length; ++i) {
            int bit = Character.getNumericValue(nums[i].charAt(i));
            bit = (bit == 0) ? 1 : 0;
            sb.append(Character.forDigit(bit, 10));
        }
        return sb.toString();
    }
}