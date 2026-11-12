class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        double res = INT_MAX;
        int n = q.size();
        vector<pair<double, int>> v;//w/q q idx
        for (int i = 0; i < n; ++i) v.push_back({(double)w[i]/q[i], q[i]});
        sort(v.rbegin(), v.rend());
        // for (int i = 0; i < n; ++i) cout << v[i].first << " " << v[i].second << endl;
        //worker taken as benchmark's wage/quality * quality of other worker >= wage of other worker
        //wage/quality of benchmark worker >= wage/quality of other workers so pick highest w/q worker
        //now price calc with first k but taking later k+1 to n as well and each time removing the highest q/w removed
        //as [benchmark's w/q >= w/q of other] so max w/q removed and next in v taken and res minimized
        //going from 0th (max) to n-k th (min) ration to take 
        //cost to be minimized = benchmark ratio * (quality of benchmark ratio + k-1 other quality)
        auto comp = [&v](const int& a, const int& b){
            return v[a].second < v[b].second;
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);//max heap to get min k quality
        for (int i = 1; i < n; ++i) {//add k-1 qual except first cuz that would be the k th
            pq.push(i);
            if (pq.size() == k) pq.pop();
        }
        pq.push(0);//first benchmarkRatio's quality

        int totalQual = 0;
        unordered_set<int> takenIdx;//the previous benchmark ratios can stay in this cuz the new benchmark 
        //ratios are the deciding factor and the elements after it are only considered
        {
            queue<int> q;//auxi
            while (!pq.empty()) {
                q.push(pq.top()); pq.pop();
            }
            while (!q.empty()) {
                totalQual += v[q.front()].second; takenIdx.insert(q.front()); q.pop();
            }
        }

        auto cmp = [&v](const int& a, const int& b){
            return v[a].second > v[b].second;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq1(cmp);//now min heap to extract min quality from pq1.top();

        for (int i = 0; i < n; ++i) if (takenIdx.find(i) == takenIdx.end()) pq1.push(i);//insert the others in pq1 arranged by min qual
        res = min(res, v[0].first * totalQual);//first benchmarkRatio * total qual
        
        for (int i = 1; i <= n - k; i++) {
            totalQual -= v[i - 1].second;
            if (takenIdx.find(i) == takenIdx.end()) {//the next benchmark ratio not among the min quality so its taken (must be removed from pq1 also)
                totalQual += v[i].second;
                takenIdx.insert(i);
            } else {//the next benchmark ratio qual alr among the min so taken alr so pick net min from pq1 thats not taken
                while (!pq1.empty() && takenIdx.find(pq1.top()) != takenIdx.end()) pq1.pop();
                totalQual += v[pq1.top()].second;
                takenIdx.insert(pq1.top());
                pq1.pop();
            }
            res = min(res, v[i].first * totalQual);//other benchmarkRatio * total qual
        }

        return res;
    }
};