class Solution {
private:
    bool palindrome(int x) {
        int X = x;
        long long ans = 0;
        while (x) {
            ans = (ans * 10) + (x % 10);
            x /= 10;
        }
        return ans == X;
    }
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[nums.size()/2];
        long long ans = LLONG_MAX;
        for (int i = 0; i <= k; ++i) {
            if (palindrome(k - i)) {
                long long a = 0;
                for (int &el : nums) {
                    a += abs(el - (k-i));
                }   
                ans = min(ans, a);
                break;
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (palindrome(k + i)) {
                long long a = 0;
                for (int &el : nums) {
                    a += abs(el - (k+i));
                }   
                ans = min(ans, a);
                break;
            }
        }
        return ans;
    }
};