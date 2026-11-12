class Solution {
public:
    long long bowlSubarrays(vector<int>& A) {
        long long res = 0;
        vector<int> s;
        for (int r = 0; r < A.size(); ++r) {
            while (!s.empty() && A[s.back()] < A[r]) { // all distinct
                s.pop_back();
                res += !s.empty();
            }
            s.push_back(r);
        }
        return res;
    }
};