class Solution {
public:
    int mod = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        // 1 loop
        long long res = 0;
        int x = 0, y = 0; // x cnt of [a,b], y cnt of >b
        for (int& i : nums) {
            if (i < a) res += x + y; // move to left
            else if (i <= b) res += y, x++; // move to middle
            else y++;
        }
        return res % mod;
    }
};
// // 2 loop
// // move to right = move to left
// // x y y x x x -> 6 steps to move 3x to left (each takes number of y to its left steps) 
// // or 2y to right (each takes number of x to its right steps)
// long long res = 0; 
// for (int i = 0, greater_equal_a = 0; i < nums.size(); i++) {
//     if (nums[i] >= a) greater_equal_a++;
//     else res = (res + greater_equal_a) % mod; // < a move to left of array
// }
// for (int i = 0, greater_b = 0; i < nums.size(); i++) {
//     if (nums[i] < a) continue; // ignore since < a vals already moved to left of array
//     if (nums[i] > b) greater_b++;
//     else res = (res + greater_b) % mod; // [a, b] move to middle of array
// }
// // note in second loop how el in [a,b] are moved instead of >b
// // b = 5
// // [<a done] 2 3 6 4 8
// // if el in [a,b] counted instead of >b that means >b 'moved' but issue is:
// // at 8 cnt of el in [a, b] = 3 but 8 doesnt have to move its alr in right segment and all
// // el >b moved to right alr so it would give +3 to res since traversing left to right which is wrong
// // hence count >b occurences so if el in [a,b] found its steps to move to middle are calc
// // same can be said for first loop - counting >=a to move <a to left
// return (int)res;