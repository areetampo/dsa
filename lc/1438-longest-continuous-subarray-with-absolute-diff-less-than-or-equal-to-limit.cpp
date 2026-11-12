class Solution {
public:
    // int longestSubarray(vector<int>& v, int l) {//m - 1 pq O(nlogn)
    //     auto c1 = [&v](const int& a, const int& b){
    //         return v[a] < v[b];
    //     };
    //     auto c2 = [&v](const int& a, const int& b){
    //         return v[a] > v[b];
    //     };
    //     priority_queue<int, vector<int>, decltype(c1)> pqMx(c1);
    //     priority_queue<int, vector<int>, decltype(c2)> pqMn(c2);
    //     int res = 0;
    //     for (int j = 0, i = -1; j < v.size(); j++) {
    //         while (pqMx.size() && v[pqMx.top()] - v[j] > l) {
    //             i = max(i, pqMx.top());
    //             pqMx.pop();
    //         }
    //         while (pqMn.size() && v[j] - v[pqMn.top()] > l) {
    //             i = max(i, pqMn.top());
    //             pqMn.pop();
    //         }
    //         res = max(res, j - i);
    //         pqMx.push(j); pqMn.push(j);
    //     }
    //     return res;
    // }
    int longestSubarray(vector<int>& v, int l) {//m - 2 deque O(n)
        deque<int> dMx;
        deque<int> dMn;
        int res = 0;
        for (int j = 0, i = 0; j < v.size(); j++) {
            while (dMx.size() && v[dMx.front()] < v[j]) dMx.pop_front();
            dMx.push_front(j);
            while (dMn.size() && v[dMn.front()] > v[j]) dMn.pop_front();
            dMn.push_front(j);
            while (dMx.size() && dMn.size() && v[dMx.back()] - v[dMn.back()] > l) {
                if (i == dMx.back()) dMx.pop_back();
                if (i == dMn.back()) dMn.pop_back();
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};