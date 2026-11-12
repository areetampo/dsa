class Solution {
    public void moveZeroes(int[] nums) {
        // int z = 0;//searches for 0 indexes
        // int nz = 0;//searches for non 0 indexes
        // while (z != nums.length && nz != nums.length) {
        //     if (z < nz && nums[z] == 0 && nums[nz] != 0) {//swap
        //         nums[z] = nums[nz];
        //         nums[nz] = 0;
        //         z++; nz++;
        //     }
        //     else if (nums[z] != 0) z++;
        //     else if (nums[nz] == 0) nz++;
        //     else nz++;
        // }

        int snowballSize = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) snowballSize++;
            else if (snowballSize > 0) {
                nums[i-snowballSize] = nums[i];
                nums[i] = 0;
            }
        }
    }
}