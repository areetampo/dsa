class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& Q) {
        //leftmost greater building req, let alice be at a, and bob at b
        //if both at same index (a = b) its the ans
        //a != b cases:
        //if the left person is at smaller building and right at greater building
        //left person can move to right buulding,
        //if both at buildings of same height, look for greater ht building to
        //righ of right person,
        //if the left person at builfing of greater ht, both must move to
        //a building to right of right person which has > ht than left person
        //building
        //now this last case is tricky, precomputing a leftmost greater vec
        //would not help eg:
        //v = 2 4 2 1 2 3 5
        //    l     r       both must move to 2nd last building (3 ht)
        //precomputed vec will give res as 2 (just right of right person)
        //and we must not store the greatest right el (remove el from v.back()
        //and taking v[0] each time cuz here it will give 5 which isnt the left
        //most greater -> basically if a greater value occurs, all v.back()
        //less than it get popped so 3 gets removed and 4 gets put as l's ans
        //which is correct but for both l and r as query, 3 is the ans) 
        //so precomputing isnt the solution, so maintain mono vec on the fly:
        //sort queries based on largest right first
        //v keeps indices
        //NOTE THAT WHEN TRAVERSING THE QUERIES A RIGHT CAN APPEAR SUCH THAT
        //THE ELEMENTS TO RIGHT OF IT NEVER WENT THROUGH v
        //THIS IS BECAUSE WE MUST START CONSIDERING FROM END OF HT[] ARRAY
        //AND NOT JUST THE INDICES PRESENT AS END IN QUERIES
        //SO KEEP A H_IDX STARTING AT END OF HT[] ARRAY AND SINCE THE QUERIES
        //ARE SORTED BASED ON DECRESING RIGHT INDICES, RUN THE HT_IDX
        //ELEMENTS THROUGH STACK UNTIL ITS > RIGHT INDEX OF QUERY, NOW
        //HT_IDX == RIGHT SO AGAIN FOR THE LAST TIME REMOVE <= FROM v
        //BUT DONT ADD RIGHT INTO THE STACK AS IT WOULD DISRUPT CALC RESULT
        //IF LEFT_HT >= RIGHT_HT ... NOTE AGAIN THAT HT_IDX ONLY PASSES THROUGH
        //STACK v IF RIGHT < HT_IDX BECAUSE ELEMENTS AFTER RIGHT ARE NEEDED
        //AND THERE CSAN BE MULTIPLE QUERIES WITH SAME RIGHT SO DONT MOVE HT_IDX
        //UNTIL RIGHT GOES TO LEFT OF IT
        //q[0] == q[1] -> can stay at same building (=res) and remove v.back()
        //until <= building at q[0] and put it in v
        //q[0] != q[1] -> one at left, other at right -> 3 cases:
        //1: left building ht < right -> remove from v.back() until its <= right
        //building
        //2: left building ht == right -> remove from v.back() until its <= right
        //building
        //3: left building ht > right -> remove from v.back() until its <= right
        //building NOW (v[0] -> v.back() is 
        //dec order of indices and height_arr[v[i]] is also dec heights)
        //and all building in v are to the right of right 
        //so now BINARY SEARCH minimum index (closest to v.back()) which
        //has its val in ht_arr > left building
        //NOTE REMOVING = AS WELL SINCE THEY HAVE BIGGER INDICES CURR SAME HT CAN BE 
        //INSERTED IN v WITH LOWER INDEX
        //in the end put right at end of v
        for (auto &i : Q) sort(i.begin(), i.end());//i[0] <= i[1] (left <= right)
        vector<int> s;//mono inc stack (vec v)
        vector<vector<int>> t;//[right, left, orig_idx]
        for (int i = 0; i < Q.size(); i++) t.push_back({Q[i][1], Q[i][0], i});
        sort(t.rbegin(), t.rend());//sorted by gratest right first
        vector<int> res(Q.size());
        int h_idx = h.size() - 1;
        for (auto &i : t) {
            int right = i[0], left = i[1], idx = i[2],
                right_ht = h[right], left_ht = h[left];
            // cout << "[" << left << "," << right << "] " << left_ht << " " << right_ht << "\n";
            while (h_idx >= right) {
                // cout << "h_idx:" << h_idx << "\n";
                while (!s.empty() && h[h_idx] >= h[s.back()]) s.pop_back();
                if (h_idx > right) s.push_back(h_idx--);
                else break;
            }
            if (right == left) res[idx] = right;
            else if (left_ht < right_ht) res[idx] = right;
            else if (s.empty()) res[idx] = -1;
            else if (left_ht == right_ht) res[idx] = s.back();
            else {
                // for (int &f : s) cout << h[f] << " "; cout << "..\n";
                int lo = 0, hi = s.size() - 1;
                while (lo <= hi) {
                    // cout << lo << " " << hi << "\n";
                    int mid = lo + (hi - lo) / 2, index = s[mid], ht = h[index];
                    //s looks like (0 -> s.back() and all indices > right)
                    //dec indices, dec heights at those indices in h[]
                    //need rightmost so index is min and ht > left_ht
                    if (ht <= left_ht) hi = mid - 1;
                    else lo = mid + 1;
                }
                // cout << hi << "\n";
                res[idx] = hi == -1 ? -1 : s[hi];
            }
            // cout << idx << "r:" << res[idx] << "-------\n";
        }
        return res;
    }
};