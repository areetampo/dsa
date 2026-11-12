class Solution {
public:
    int reverse(vector<int>& mapping, int x) {
        int l = 0, X = x; 
        while (X >= 10) {
            l++;
            X /= 10;
        }
        int i = pow(10, l), res = 0;
        while (i) res = res * 10 + mapping[(x / i) % 10], i /= 10;
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [this, &mapping](int a, int b){
            return reverse(mapping, a) < reverse(mapping, b) ? a < b ? a < b : a > b : a < b ? a > b : a < b;
        });
        return nums;
    }
};