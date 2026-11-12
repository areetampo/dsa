class Solution {
public:
    bool closeStrings(string a, string b) {
        if (a.length() != b.length()) return 0;
        vector<int> A(26, 0);
        for (char &ch : a) A[ch - 'a']++;
        vector<int> B(26, 0);
        for (char &ch : b) B[ch - 'a']++;

        //basically should have same chars with same freq as operation 1 (swaps) can be done anytime
        //eg cabbba, abbccc, same chars, freq impo, swaps can be done anytime
        
        for (int i = 0; i < 26; ++i) {
            if (A[i] && !B[i] || !A[i] && B[i]) return 0;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0; i < 26; ++i) {
            if (A[i] != B[i]) return 0;
        }
        return 1;
    }
};