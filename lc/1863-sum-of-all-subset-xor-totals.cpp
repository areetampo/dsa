class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        //O(n) concept:
        //eg : [5, 6], subsets:
        //[] -> XOR = 000
        //[5] -> XOR = 101
        //[6] -> XOR = 110
        //[5,6] -> XOR = 011
        //suppose for bit 0 (which is only set in value 5 of arr) -> half subsets have 0th bit set (2 ^ n-1 subsets)
        //now suppose if another number added to nums eg 1 (001 binary, has 0th bit set), it will make impact in all 
        //subsets with 2 choices -> being part of a subset or not being part of a subset, so in end total subsets will
        //doubled and their XOR will look like
        //000 , 000 ^ 1 = 001
        //101 , 101 ^ 1 = 100
        //110 , 110 ^ 1 = 111
        //011 , 011 ^ 1 = 010
        //so total 8 subsets and notice how with the addition of a val in the arr with its 0th bit (bit in perspective)
        //that is set, the total number of subsets with their 0th bit set is still 2 ^ n - 1, cuz with the addition of 1
        //all the previous 0th bit unset became set, set became unset + the prev unset/set remained!
        //so at the end of the day, if any number in the array has its i th bit set -> it contributes
        //(2 << i) * total subsets its present in = (2 << i) * (2 ^ n - 1)
        int OR = 0;
        for (int &i : nums) OR |= i;
        return OR * pow(2, nums.size() - 1);
    }
};