class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;//val, vis status
        for (int &i : nums) m[i] = 0;
        int res = 0;
        for (auto i = m.begin(); i != m.end(); i++) {
            int val = i->first, vis = i->second;
            //vals in consecutive order vis beforehand so non vis means it is +/-2 from other sequence's start/end
            if (vis) continue;
            m[val] = 1;
            int consecutive = 1;
            while (m.find(++val) != m.end()) {
                consecutive++;
                m[val] = 1;
            }
            val = i->first;
            while (m.find(--val) != m.end()) {
                consecutive++;
                m[val] = 1;
            }
            res = max(res, consecutive);
        }
        return res;
    }
};