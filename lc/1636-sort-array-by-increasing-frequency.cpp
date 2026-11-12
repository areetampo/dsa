class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> v(201, 0);
        for (int &i : nums) v[i + 100]++;
        sort(nums.begin(), nums.end(), [v](int a, int b){
            return v[a + 100] == v[b + 100] ? a > b : v[a + 100] < v[b + 100];
        });
        return nums;
    }
};