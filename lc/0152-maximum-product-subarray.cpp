class Solution {
public:
    int maxSubProd(int s, int e, vector<int>& v) {
        if (s == e) return v[s];
        int negative = 0;
        for (int i = s; i <= e; i++) {
            if (v[i] < 0) negative++;
        }
        if (negative % 2 == 0) {
            int prod = 1;
            for (int i = s; i <= e; i++) prod *= v[i];
            return prod;
        }
        int i = s, j = e;
        while (i <= e && v[i] > 0) i++;
        while (s <= j && v[j] > 0) j--;
        //if i == s && j == e -> [- + - + -] -> -ves at ends of arr and sz != 1 and odd -ve -> min 3 els exist
        //                        x . . . .  
        //                        . . . . x
        //so when calc leftProd -> rightProd = 0 and vice versa
        //else eg: [+ - + - + - +]
        //          . x . . . . .
        //          . . . . . x .
        //note : if -ves = 1 -> division pivot [tle in [0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0]]
        // skip with left -ve
        int leftProd = i != s, rightProd = 1;
        for (int x = s; x < i; x++) leftProd *= v[x]; 
        for (int x = e; x > i; x--) rightProd *= v[x];
        int res = max(leftProd, rightProd);
        // cout << leftProd << " " << rightProd << endl;
        // skip with right -ve
        leftProd = 1, rightProd = j != e;
        for (int x = s; x < j; x++) leftProd *= v[x]; 
        for (int x = e; x > j; x--) rightProd *= v[x]; 
        // cout << leftProd << " " << rightProd << endl;
        return max(res, max(leftProd, rightProd));
    }
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, n = nums.size(), i = 0;
        while (i < n) {
            while (i < n && !nums[i]) i++;
            int j = i;
            while (j < n && nums[j]) j++;
            if (i < n) //prevent execution for all 0s array
                res = max(res, maxSubProd(i, j - 1, nums));//separating 0s
            i = j;
        }
        return res <= 0 ? *max_element(nums.begin(), nums.end()) : res;
    }
};