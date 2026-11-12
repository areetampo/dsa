class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //eg: [1,5,10] n = 20
        //i = 0 at 1 done i++ and is max currently then 2 needed so PATCH [2] then max is 1 + 2 = 3
        //then 4 absetnt so PATCH [4] max is 3 + 4 = 7 now i = 1 at 5 so max = 7 + 5 = 12 and i = 2
        //now 12 > [i] = 10 so 12 + 10 = 22 > n -> total 2 patches
        //NOTE THAT FOR MAX: ALL ELEMENTS IN [1, MAX] REACHABLE AND NEXT ELEMENT IS NUMS > MX MEANS
        //FOR IT TO REACH MORE NUMBERS WILL BE REQUIRED BUT WE CAN ADD IT TO OUR MAX ONLY EG:
        //MAX = 7 AND NUMS[I] = 9 SO CURRENTLY [1,7] sALL REACHABLE AND TO REACH 9, MAX + 1 = 8 MUST BE PATCHED
        //THAT MEANS THE ELEMENTS REACHABLE NOW ARE [1, 15] AND MAX = 15 SINCE [1, 7] WERE ALR REACHABLE
        //AND NOW 8 IS PATCHED SO [8, 15] CAN BE REAHCED USING 8 AND ANY OF THOSE [1, 7], stop when max >= n
        long long mx = 0, res = 0;
        for (int &a : nums) {
            if (mx >= n) break;
            while (mx + 1 < a && mx < n) {
                // cout << mx + 1 << " ";
                mx += mx + 1;
                res++;
            }
            mx += a;
        }
        //lets say arr ended and maxx = 10 but n = 50 so more patches needed, right now [1, 10] reachable
        //add patch = [11] -> so [1, 21] reachable then add patch 22 so [1, 42] reachable and last patch 43
        while (mx < n) { mx += mx + 1; res++; }
        return res;
    }
};