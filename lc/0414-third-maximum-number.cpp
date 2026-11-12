class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int min = nums[0]; 
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i])
            min = nums[i];
        }//start from min
        int max1 = min, max2 = min, max3 = min; 
        for (int i = 0; i < nums.size(); i++) {
            if (max1 < nums[i])
            max1 = nums[i];
        }//get the max
        for (int i = 0; i < nums.size(); i++) {
            if ((max2 < nums[i]) && (nums[i] != max1))
            max2 = nums[i];
        }//max2 must not be equal to max1 eg: [1,2] array problem
        for (int i = 0; i < nums.size(); i++) {
            if ((max3 < nums[i]) && (nums[i] != max1) && (nums[i] != max2))
            max3 = nums[i];
        }//max2 may = max3 if 2 element array and both the minimum one eg: [1,2]
        if (!((max3 < max2) && (max2 < max1)))//if doesn't have 3 ddistinct element
        return max(max1, max(max2, max3));//for max3 showcase
        return max3;
    }
};