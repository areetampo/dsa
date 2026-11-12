class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {//O(n) time+space solution
        map<int, int> m;
        for (int &i : arr) ++m[i];
        vector<int> v(arr.size() + 1, 0);//v[idx] = number of el with freq idx
        for (auto i = m.begin(); i != m.end(); ++i) {
            ++v[i->second];
        }
        //now from start of v (least freq els) do: k -= idx * v[idx] = freq * num of els with that freq
        for (int i = 1; i < v.size(); ++i) {//start from freq = 1 as none with freq = 0 obviously
            if (!k) break;
            if (k >= v[i] * i) {
                k -= v[i] * i;
                v[i] = 0;
            }
            else {
                v[i] -= k/i;
                k = 0;
            }
        } 
        int res = 0;
        for (int i = 1; i < v.size(); ++i) {
            res += v[i];
        }
        return res;
    }
};