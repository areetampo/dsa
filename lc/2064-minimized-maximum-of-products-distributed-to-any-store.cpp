class Solution {
public:
    bool can_place(int n, vector<int>& q, int max_products) {
        int req_stores = 0;
        for (int &i : q) req_stores += (i + max_products - 1) / max_products;
        cout << req_stores << "\n";
        return req_stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        //minimize the max num of products placed per store
        //in the can_place method: returns true if they can be placed in 
        //<= n stores with the max number of products in any store being mid
        //so reduce this value since the goal is to minimize (it would keep
        //getting lower until they can be placed in exaclty n strores [as
        //req_stores (=mid) decreases, req_stores increases (<= n)])
        //if req_stores > n means the number of items (mid) placed in each store
        //is too low and hence more stores are req so increase the number of items
        int lo = 1, hi = *max_element(q.begin(), q.end());
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            cout << lo << " " << mid << " " << hi << " ";
            if (can_place(n, q, mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};