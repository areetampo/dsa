class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {//similar to 502 IPO
        //o(nlogn + mlogm)
        vector<pair<int, int>> v;//difficulty, profit
        for (int i = 0; i < d.size(); i++) v.push_back({d[i], p[i]});
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        priority_queue<int> pq;//max profit until j th difficulty
        int i = 0;//track until how much difficulty level can j th worker handle -> then pick the max profit
        int res = 0;
        for (int j = 0; j < w.size(); j++) {
            int k = i;
            while (k < v.size() && w[j] >= v[k].first) {
                pq.push(v[k].second);
                k++;
            }
            //if k = i means the worker can't do any job so onto next worker
            if (pq.size()) 
                res += pq.top();//no pop cuz multiple workers can do same job if it has max profit
            i = k;
        }
        return res;
    }
};