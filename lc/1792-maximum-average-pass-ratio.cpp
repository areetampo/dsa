class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        //max heap priority by:
        //after adding 1 extra student to each class, which class gives the
        //max increase in ratio
        //if 2 classes give same increase in ratio, pick the one with smaller
        //number of students : eg : 2/5 = 9/19 : adding 1 student to each
        //class makes the ratios to be 0.5 but significant change is for the
        //first class
        //note: if the pass/total students are equal and after adding 1 the 
        //new ratio is also same for both: that means both vals are just same!
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](const auto& a, const auto& b){
            auto [p1, t1] = a;
            auto [p2, t2] = b;
            double x = (p1 + 1.0) / (t1 + 1) - (p1 + 0.0) / t1, 
                y = (p2 + 1.0) / (t2 + 1) - (p2 + 0.0) / t2;
            if (x == y) return t1 - p1 > t2 - p2;
            return x < y;
        })> pq;
        double res = 0;
        for (auto &i : c) {
            if (i[0] == i[1]) {res++; continue;}//ratio = 1
            pq.push({i[0], i[1]});
        }
        if (!pq.empty()) {
            while (e--) {
                auto [pass, total] = pq.top();
                // cout << pass << " " << total << "\n";
                pq.pop();
                pq.push({pass + 1, total + 1});
            }
            while (!pq.empty()) {
                auto [pass, total] = pq.top(); pq.pop();
                // cout << (pass + 0.0) / total << "\n";
                res += (pass + 0.0) / total;
            }
        }
        return res / c.size();
    }
};