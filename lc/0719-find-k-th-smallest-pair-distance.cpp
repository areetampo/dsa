class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    int lo = 0, hi = nums[n - 1] - nums[0];
    //search space is min diff = 0 and max diff = nums[n - 1] - nums[0]
    //find number of pairs with difference less than or equal to diff
    //how to find number of pairs? eg: 
    //[1,2,5,6,7,10,11], mid = 3
    // i j -> diff = 1, move j until the nums[j] - nums[i] <= diff then calc the pairs using size of the subarray encased with i and j
    //now move i so its at a bigger number now (nums[j] - nums[i] will be lesser so move j now so until nums[j] - nums[i] <= diff and continue until j reaches n - 1
    //if the number of pairs is less than k then more pairs are needed hence the diff should be greater to include more pairs so lo -> diff + 1
    //if it is greater or equal then the diff should be lesser / equal to include less pairs so hi -> diff
    //in end -> lo is the kth smallest pair diff
    while (lo < hi) {
        int diff = lo + (hi - lo) / 2, cnt = 0;
        // dbg(diff);
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= diff) j++;
            //pairs i forms with next elements (i + 1, i + 2, ..... j - 1) whose difference <= diff
            cnt += j - i - 1;
            // dbg(i); dbg(j);
            // dbg(cnt);
        }
        if (cnt < k) lo = diff + 1;
        else hi = diff;
        // small_line();
    }
    return lo;
    }
};