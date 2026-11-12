class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            string s1 = to_string(a), s2 = to_string(b);
            return s1 + s2 > s2 + s1;
        });
        string res = "";
        for (int &i : nums) res += to_string(i);
        //zeros are ok as long as they are in end of string (will be in end of array after sort)
        //but if array of all zeros, final answer is 0
        return res[0] == '0' ? "0" : res;
    }
};