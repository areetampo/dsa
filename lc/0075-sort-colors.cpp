class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, m = 0;
        //dutch flaf algo
        //if m = 0 -> swap with l -> l++ m++, only 1 can be at m after swap cuz
        //coming from l -> that idx is traversed n if it was: 2? -> moved to j, 0? -> efeectively no swap
        //if m = 2 -> swap with h -> h--, dont move m cuz suppose h was 0 and now m = 0 to be swapped with l
        //in end all 1s in middle
        while (m <= h) {
            if (nums[m] == 0) {
                swap(nums[l++], nums[m++]);
            } else if (nums[m] == 2) {
                swap(nums[m], nums[h--]);
            } else m++;
        }
    }
};