class Solution {
public:
    int minOperations(string s1, string s2) {
        if (s1 == "1" && s2 == "0") return -1; // edge case otherwise s1 to s2 always possible
        // 0s can be made 1s in 1 step min
        // 1s that need to be 0s:
        // 2 consecutive 1s need 1 step min hence even 1s that need to become 0s steps = their cnt / 2
        // if theres an extra 1 it always needs 2 steps since eventually it would be surrounded by
        // atleast one 0 that doesnt need to change since its position is 0 in s2 also
        // for the 1 that needs to become 0, the 10 or 01 become 11 then 00 = 2 steps
        int res = 0, one_to_zero = 0;
        for (int i = 0; i < s1.size(); i++) {
            // s1[i] == s2[i] ignored
            if (s1[i] == '1' && s2[i] == '0') {
                one_to_zero++;
            } else {
                res += s1[i] == '0' && s2[i] == '1';
                res += one_to_zero / 2 + (one_to_zero & 1) * 2;
                one_to_zero = 0;
            }
        }
        return res + one_to_zero / 2 + (one_to_zero & 1) * 2;
    }
};