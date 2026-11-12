class Solution {
public:
    bool canChange(string A, string B) {
        //try to match chars one by one while maintaing a buffer
        //since length of both strings are equal, just check if correct number of
        //L and R can be placed (in the correct order as well) as rest are '_' only
        //traversing left to right in both string
        //NOTE: only L and R of string a can move
        //2 cases:
        //L: since L can't move right, keep track of L cnt in b
        //if L appears in a, decrement L_cnt_b, if goes below 0 means insufficient 
        //L since those Ls in a cannot move left to make up the Ls in B [also note 
        //that each time R appears in b L_cnt_b should be 0 since those Ls cant 
        //move beyond that R in b and will never be matched so return 0]
        //R: since R can't move left, keep track of R cnt in a
        //if R appears in b, decrement R_cnt_a, if goes below 0 means insufficient 
        //R since those Rs in a cannot move right to make up the Rs in B [also note 
        //that each time L appears in a R_cnt_a should be 0 since those Rs cant 
        //move beyond that L in a and will never be matched so return 0]
        int L_cnt_b = 0, R_cnt_a = 0;
        for (int i = 0; i < A.size(); i++) {
            char a = A[i], b = B[i];
            if (a == 'R') R_cnt_a++;
            if (b == 'R') if (--R_cnt_a < 0 || L_cnt_b > 0) return 0;
            if (b == 'L') L_cnt_b++;
            if (a == 'L') if (--L_cnt_b < 0 || R_cnt_a > 0) return 0;
            // cout << L_cnt_b << " " << R_cnt_a << "\n";
        }
        return L_cnt_b + R_cnt_a == 0;//for cases like A = _R, B = L_
    }
};