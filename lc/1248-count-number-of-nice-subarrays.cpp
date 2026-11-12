class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {//method - 2 -> lee's approach in soln
        int i = 0, j = 0, n = nums.size(), l = 0, r = 0;

        while (j < n && nums[j] % 2 == 0) j++;
        if (j == n) return 0;
        //j at first odd
        l = j - i;//number of elements before 1st odd
        i = j;//i at 1st odd element now
        // cout<<i<<" "<<j<<" "<<l<<" "<<endl;
        --j;//j was at first odd and doing --k if == 0 then would have to put && k in while loop [for k = 1 given]
        while (++j < n) {
            if (nums[j] % 2 && !--k) break;
        }
        if (k) return 0;//not k odd elements in array
        // cout<<i<<" "<<j<<" "<<l<<" "<<endl;
        //j at kth odd now
        int f = j;
        while (++j < n && nums[j] % 2 == 0) {}
        //j at k + 1 th odd now
        r = j - f - 1;//elements between k th odd and k + 1 th odd
        // cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;

        int res = (l + 1) * (r + 1);
        // cout << res << endl;
        while (j < n) {
            // cout << i << " " << j << endl;
            l = 0, r = 0;
            while (nums[++i] % 2 == 0) l++;
            while (++j < n && nums[j] % 2 == 0) r++;
            res += (l + 1) * (r + 1);
        }
        return res;
    }
};