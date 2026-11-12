class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        //sort events by end time
        //now consider each slot and its value
        //for other value: consider a slot with start > end time of chosen slot
        //(can use binary search) then from that slot to end slot -> choose the one 
        //with maximum value (use suffix max arr)
        //above is wrong cus of eg: [1,3,2],[4,5,2],[1,5,5]
        //considering the first slot, the second slot lands at 4-5 but sufmax is 5 
        //coming from the next 1-5 slot which is wrong cuz start = 1 < end = 3
        //correct approach -> sort by start times
        //so found next slot for each considered slot has start time greater 
        //than considered slot's end time and since sorted by start times, all next
        //slots have start time greater than considered slot's end time so doesnt
        //matter where suf_max comes from
        sort(e.begin(), e.end());
        // for (auto &i : e) cout << "[" << i[0] << "," << i[1] << "," << i[2] << "],";
        // cout << "\n";
        int n = e.size();
        vector<int> suf_max = {e[n - 1][2]};
        for (int i = n - 2; i >= 0; i--) 
            suf_max.push_back(max(suf_max[n - 2 - i], e[i][2]));
        reverse(suf_max.begin(), suf_max.end());
        // for (int &i : suf_max) cout << i << " "; cout << "\n";
        int res = 0;
        for (int i = 0; i < n; i++) {
            int end = e[i][1], value = e[i][2];
            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                //start time <= end so move right where greater start values exist
                if (e[mid][0] <= end) lo = mid + 1;
                else hi = mid - 1;
            }
            // cout << i << " " << lo << " " << value + (lo < n ? suf_max[lo] : 0) << "\n";
            //now lo is at correct idx so pick suf_max value at that if < n
            res = max(res, value + (lo < n ? suf_max[lo] : 0));
        }
        return res;
    }
};