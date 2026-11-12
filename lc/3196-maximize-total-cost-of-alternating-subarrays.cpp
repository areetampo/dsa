class Solution {
public:
    long long maximumTotalCost(vector<int>& v) {
        //house robber dp on seq of -ve elements
        //cannot make 2 consecutive elements +ve
        //if there's a +ve element in front of a -ve sequence, first -ve can
        //become +ve otherwise stays -ve (if -ve seq at start of arr)
        long long res = 0; int n = v.size();
        for (int i = 0, j; i < n; i = j) {
            while (i < n && v[i] >= 0) res += v[i++];
            j = i;
            while (j < n && v[j] < 0) j++;
            if (i == j) break;//both = n
            vector<long long> dp(j - i, 1e18);
            dp[0] = i == 0 ? 0 : v[i];
            if (dp.size() > 1) dp[1] = min((long long)v[i + 1], dp[0]);
            //max value is obtained by not taking 2 consecutive elements and
            //considering all values to be +ve -> to replicate with -ve values ->
            //consider min from taking curr + dp 2 elements back or 1 step back dp
            //if curr element is not considered
            //so in end absolute of that value represent the elements in the -ve
            //seq that could be made +ve for max sum
            //now to add in res, whole sum of the seq + 2 * abs(dp.back())
            for (int k = 2; k < dp.size(); k++) {
                dp[k] = min(dp[k - 1], v[i + k] + dp[k - 2]);
            }
            res += accumulate(v.begin() + i, v.begin() + j, 0ll) +
                2 * abs(dp.back());
            // cout << i << " " << j << " " << res << "\n";
        }
        return res;
    }
};
//greedy approach fails at [4,-5,-3,-2,-4,4]
// int n = v.size();
// long long res = 0;
// for (int i = 0; i < n; i++) {
//     if (v[i] >= 0) res += v[i];
//     else {
//         long long a = 0, b = 0;
//         int j = i;
//         while (j < n && v[j] < 0) {
//             if ((j - i) % 2) a += abs(v[j]);//why using j - i explained below
//             else b += abs(v[j]);
//             j++;
//         }
//         cout << a << " " << b << "\n";
//         if (i == 0) {
//             //arr starts with -ve elements
//             //so all the -ve element's absolute vals end up as
//             //- - + - + ... or - + - + - + ... opposed to
//             //- + - + ... or + - + - ... when there is a +ve element before
//             //now b will always contain the first elemnent since for
//             //(j - i) % 2 == 0, the abs val gets added to b at i = j
//             res += max(a - b, b - a + 2 * v[i]);
//             //2 * to subtract v[i] from b as its absolute val got added
//         }
//         else res += max(a - b, b - a);
//         i = j - 1;
//     }
//     cout << res << "\n";
// }
// return res;
