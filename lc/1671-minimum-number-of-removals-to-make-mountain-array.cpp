class Solution {
public:
    int ins(int idx, vector<int>& temp, vector<int>& v) {
    if (temp.empty()) {
        temp.push_back(idx);
        return idx;
    }
    int l = 0, r = temp.size() - 1, el = v[idx];
    // dbg(temp);
    while (l <= r) {
        int m = l + (r - l) / 2;
        // dbg(temp[l]); dbg(temp[r]); dbg(temp[m]);
        //= not allowed since mountain arr is strictly inc / dec
        if (el == v[temp[m]]) break;
        else if (el > v[temp[m]]) l = m + 1;
        else r = m - 1;
    }
    if (l == temp.size()) temp.push_back(idx);
    else temp[l] = idx;
    // dbg(temp);
    return temp.back();
    }
    int minimumMountainRemovals(vector<int>& v) {
    //for each idx: lis to its left and longest decreasing subsequence to its right
    //indices precomputed (left: final idx of lis, right: final idx of lds) + seq len
    //and stored in n length arrays (done in nlogn with bin search)
    //now trav all idx and pick len = left + right | now do len-- if case 1: idx of inc subsq 
    //and dec dubsq same or case 2: vals at those idx same (both these cases can be grouped
    //as v[idxIncSubsq] == v[idxDecSubsq] (idx same so val also same)) cuz mountain arr:
    //1 2 3 4 is the inc subsq
    //         4 3 2 1 is the dec subsq so if peak val is same (counted in both lis or lds
    //must do -1)
    //and res = max(res, n - len) for all n - 2 idx (not 0 or n - 1)
    vector<pair<int, int>> lis, lds;//lis, lds final indices + len
    vector<int> lisTemp, ldsTemp;//temp arrays for the procedure simulation, store indices
    //note: since all suffix lds req so for each greater number encountered 
    //(while going right to left in v) insert it in ldsTemp at end so lds[i] in dec order
    //but v[lds[i]] in inc order
    int n = v.size();
    for (int i = 0; i < n; i++) {
        // cerr << i << " left:" << endl;
        lis.push_back({ ins(i, lisTemp, v), lisTemp.size() });
        // cerr << "right:" << endl;
        lds.push_back({ ins(n - 1 - i, ldsTemp, v), ldsTemp.size() });
        // small_line();
    }
    reverse(lds.begin(), lds.end());//so lds[0] contains suffix lds [0...n-1]
    // dbg(lis); dbg(lds);
    int res = n;
    for (int i = 1; i < n - 1; i++) {
        int incSeqCnt = lis[i].second, decSeqCnt = lds[i].second,
        valAtLastIncIdx = v[lis[i].first], valAtLastDecIdx = v[lds[i].first];
        //impo condition: if incSeqCnt or decSeqCnt <= 1 then no mountain possible 
        //eg: { 100,92,89,77,74,66,64,66,64 } at 92 (idx = 1) -> inc cnt = 1, dec cnt = 6
        //but if actually mountain arr then at idx = 2 inc count should be 2 cuz
        // [x, y, z] where y > x, z so inc cnt till y > 1 (same can be said for dec cnt seq)
        if (incSeqCnt <= 1 || decSeqCnt <= 1) continue;
        res = min(res, n - (incSeqCnt + decSeqCnt - (valAtLastIncIdx == valAtLastDecIdx)));
        // dbg(i); dbg(res);
    }
    return res;
    }
};