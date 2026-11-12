class Solution {
public:
    bool isIdealPermutation(vector<int>& v) {
        //global >= local always and ALL LOCAL INV ARE GLOBAL INV
        //so if an el x at i and y at j where x > y
        //and i - j > 1 -> counted as global so global cnt inc and local will never = global
        //ANSWER: JUST CHECK IF THERE IS A INV THAT IS GLOBAL AND NOT LOCAL
        //only way global = local is through pairs (x, y) -> x > y and idx[y] - idx[x] == 1 cuz
        //something like 2 1 4 3 6 5 and most importantly
        //sets of 2 and prev 2 never greater than next 2
        //and since nums contains elemnts from 0 to n-1
        //i can be at i or i + 1
        //eg 0 at 0th (correct pos) or 1st
        //if its displaced >= 2 pos -> global inv != local inv
        //eg
        //let x = 7 be displaced 2 pos to the left -> that means -> there r 2 elements smaller than x to its right
        //1 2 3 4 [7 5 6] 8 9
        //         <-> local
        //         <-> global
        //         <---> global
        //1 2 3 4 [7 6 5] 8 9
        //         <-> local
        //           <-> local
        //           <-> global
        //         <-> global
        //         <------> global
        //now let x = 5 displaced to the right -> 2 els > x to its left
        //1 2 3 4 [6 7 5] 8 9
        //           <-> local
        //           <-> global
        //         <---> global
        //1 2 3 4 [7 6 5] 8 9
        //         <-> local
        //           <-> local
        //           <-> global
        //         <-> global
        //         <------> global
        for (int i = 0; i < v.size(); i++) {
            if (abs(i - v[i]) > 1) return 0;
        }
        return 1;
    }
};