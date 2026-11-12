class Solution {
public:
    int countSubarrays(vector<int>& v, int k) {
        //let <k = -1, >k = 1, =k = 0 so find subarrs with sum = 0 and 1
        //store cnt of presum from k_pos -> 0 (means postsum of 0 -> k_pos)
        int k_pos = 0;
        for (int i = 0; i < v.size(); i++) if (v[i] == k) {k_pos = i; break;}
        unordered_map<int, int> m;
        m[0] = 1;//start is k itself (k_pos) where sum = 0
        for (int i = k_pos - 1, sum = 0; i >= 0; i--) {
            sum += v[i] < k ? -1 : 1;
            m[sum]++;
        }
        //all subarrs from left until k_pos which have sum = 0 and 1 1
        int res = m[0] + m[1];
        //traverse right and res += all subarrs in map - running sum = 0 and 1
        for (int i = k_pos + 1, sum = 0; i < v.size(); i++) {
            sum += v[i] < k ? -1 : 1;
            res += m[-sum] + m[-sum + 1];
        }
        return res;
    }
};