class Solution {
public:
    int minimumDeletions(string s) {//same as 926 as deletion is same as turning ba to aa or bb (monotone)
        int bCnt = s[0] == 'b', res = 0;
        //whenever there is a 'a'
        //as it is the last character for the current 0 <--> i substring (or solution until i)
        //start from i = 1 because string of len 1 needs 0 deletions
        //so at each 'a', two choices
        //either delete all previous b (bCnt) or deletions previously (res) delete current a (+1) 
        for (int i = 1; i < s.length(); i++) {
            char c = s[i];
            if (c == 'a') {
                res = min(res + 1, bCnt);
            } else bCnt++;
            // dbg(res);
        }
        return res;
    }
};