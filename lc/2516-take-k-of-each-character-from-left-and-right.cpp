class Solution {
public:
    int takeCharacters(string s, int k) {
        int ch[3] = {0}; 
        for (char &c : s) ch[c - 97]++;
        if (ch[0] < k || ch[1] < k || ch[2] < k) return -1;
        //approach: sliding window
        //range [i, j) represents excluded characters
        //if each character count >= k -> res can be calculated by minimizing
        //the total taken chars given by n - (j - i) [range [i, j) excluded]
        //and remove char at j and move j to right for next check
        //else any character count < k -> move i to right including that character
        int res = 1e9, n = s.size(), i = 0, j = 0;
        while (j < n) {
            if (ch[0] >= k && ch[1] >= k && ch[2] >= k) {
                res = min(res, n - (j - i));
                ch[s[j++] - 97]--;
            } else ch[s[i++] - 97]++;
        }
        //in the end j moved to n (means char at j - 1 excluded)
        //so check again if a new minimum number of taken chars achievable
        //deletions = [i, n - 1] or [i, j)
        if (ch[0] >= k && ch[1] >= k && ch[2] >= k)
            res = min(res, n - (j - i));
        return res;
    }
};