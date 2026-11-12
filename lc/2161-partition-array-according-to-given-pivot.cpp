class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, pivot);
        int lesser = 0, greater = n - 1, i = 0, j = n - 1;
        while (i < n || j >= 0) {
            if (i < n && nums[i] < pivot) res[lesser++] = nums[i++];
            else if (i < n && nums[i] >= pivot) i++;
            else if (j >= 0 && nums[j] > pivot) res[greater--] = nums[j--];
            else j--;
            // cout << lesser << " " << greater << " | " << i << " " << j << "\n";
            // for (int& k : res) cout << k << " "; cout << "\n";
        }
        return res;
    }
};