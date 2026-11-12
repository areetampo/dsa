class Solution {
public:
    int minimumIndex(vector<int>& a) {
        int candid = a[0], n = a.size();
        for (int i = 1, local_cnt = 1; i < n; i++) {
            if (a[i] == candid) local_cnt++;
            else if (--local_cnt == 0) candid = a[i], local_cnt = 1;
        }
        int candid_cnt = count(a.begin(), a.end(), candid);
        cout << candid << " " << candid_cnt;
        if (candid_cnt <= n / 2) return -1;
        for (int i = 0, cnt = 0; i < n; i++) {
            cnt += a[i] == candid;
            if (cnt > (i + 1) / 2 && candid_cnt - cnt > (n - 1 - i) / 2)
                return i;
        }
        return -1;
    }
};