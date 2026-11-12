class Solution {
public:
    int minimumSize(vector<int>& v, int max_oper) {
        //heap will not work since dont know how to divide, eg:
        //8 can be divided in 4 4 or 2 3 3 and same for other elements
        //minimize max balls in a bag using binary search on balls per bag
        //mid will be the max balls in a bag after dividing
        //total oper for dividing is sum of (ceil of each v[i] / mid - 1)
        //eg:
        //8 balls for max 3 -> 2 steps (8 -> 5 3 -> 2 3 3)
        //8 balls for max 4 -> 1 steps (8 -> 4 4)
        //8 balls for max 2 -> 3 steps (8 -> 6 2 -> 4 2 2 -> 2 2 2 2)
        //8 balls for max 5 -> 1 steps (8 -> 3 5)
        //each time dividing requires < max_oper means more oper can be used
        //to minimize the max balls in a bag (mid can be reduced)
        //otherwise inc mid (more operations means lesser balls per bag)
        //target to reach for mid is max_oper
        int lo = 1, hi = *max_element(v.begin(), v.end());
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            auto opers = accumulate(v.begin(), v.end(), 0, 
                [mid](const auto& balls, const int& i){
                    return balls + ceil((double)i / mid) - 1;
                });
            cout << lo << " " << hi << " " << mid << " " << opers << "\n";
            if (opers <= max_oper) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};