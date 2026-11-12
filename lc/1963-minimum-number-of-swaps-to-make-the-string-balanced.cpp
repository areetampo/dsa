class Solution {
public:
    int minSwaps(string s) {
        //delete the [] from string -> left with ]]][[[ -> note cnt([) == cnt(])
        //and to balance cnt number of ] and [ -> 1 swap -> []][[]
        int cnt = 0, open = 0;
        for (char &c : s) {
            if (c == '[') open++;
            else if (open) open--;
            else cnt++;
        }
        return (cnt + 1) / 2;
    }
};