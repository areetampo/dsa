class Solution {
public:
    //m-1 max heap O(k^2) eg: [99,100,101...]: outer loop, [1,1,1...]: inner loop
    //-> 2 loops nested for each i of n1 for each j of n2
    //add sum in pq, max gets popped out if size > k and if size = k and the i + j >= pq.top() means
    //it will just be popped and next elements also poppeed out only since arrays sorted
    //m-2 min heap -> O(klogk)
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        //sum, indexes | min heap approach
        //add n1[0] paired with k elements of n2
        for (int i = 0; i < min(k, (int)n2.size()); ++i) pq.push({n1[0] + n2[i], {0, i}});
        //now pop out top pair (it will be min sum) and add next pair:
        //that number of n2 paired up with next index of n1
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            auto top = pq.top(); pq.pop();
            int n1Idx = top.second.first, n2Idx = top.second.second;
            cout << n1[n1Idx] << " " << n2[n2Idx] << endl;
            res.push_back({n1[n1Idx], n2[n2Idx]});
            if (n1Idx < n1.size() - 1) {
                pq.push({n1[n1Idx + 1] + n2[n2Idx], {n1Idx + 1, n2Idx}});
            }
        }
        return res;
    }
};