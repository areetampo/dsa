class Solution {
public://refer to q5 longest palindromic substring
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n;) {
            int j = i;
            while (s[i] == s[j]) ++j;
            int left = i - 1, right = j;
            while (0 <= left && right < n && s[left] == s[right]) {
                --left; ++right;
            }
            //then left+1 to i-1 or j to right-1, total substr: ((i-1-(left+1)) or (right-1-(j))) + 1
            res += right - j;
            //i to j-1 same: suppose x len of same chars, total substr: 1 + 2 + 3 + ... + x
            res += (j - i) * (j - i + 1) / 2;
            //now trail of same chars included so shift i to idx where diff char appears
            //eg: xyzaaaamno
            //       i   j
            //doing ++i not beneficial as in next iteration:
            //    xyzaaaamno
            //        i  j
            //alr counted subtrings of a now repeating 
            i = j;
        }
        return res;
    }
};