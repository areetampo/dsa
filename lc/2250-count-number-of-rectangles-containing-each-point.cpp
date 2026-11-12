class Solution {
public:
    int search(vector<int>& r, int i) {
        int lo = 0, hi = r.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, val = r[mid];
            // cout << mid << " " << val << "\n";
            if (val >= i) hi = mid - 1;
            else lo = mid + 1;
        }
        // cout << i << " " << lo << "\n";
        return lo;
    }
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
        //cannot sort and perform binary search for both coordinates:
        //lets say we did for x_coordinate so now we know total points to the
        //right of found index (including found index) having x >= x_coordinate
        //BUT SINCE WE SORTED THE INPUT RECTANGLES, THE X COORDINATE ONLY IS IN
        //ONLY IS IN INCREASING ORDER I.E. 
        //RECT[I][0] <= RECT[I + 1][0] (0 <= I < RECT.SIZE - 1)
        //AND THE Y COORDINATES MAY NOT NECESSARILY BE SORTED, SO CANNOT 
        //PERFORM BINARY SEARCH ON THEM BUT HERE'S THE CATCH:
        //x <= 1e9 and y <= 100, so create 0 -> 100 bucket to store x 
        //coordinates whose y is in the 0 -> 100 range accordingly
        //then for each point, say p[i] = {x, y} :
        //for all y_coordinates >= y (guaranteeing that the found rectangle's
        //y_coordinates >= y), binary search for x_coordinates >= x,
        //this way guaranteed found rectangles with both x and y coord >=
        //point's {x, y} which is the result
        vector<vector<int>> r(101);
        for (auto &i : rect) r[i[1]].push_back(i[0]);
        for (auto &i : r) sort(i.begin(), i.end());
        vector<int> res;
        for (auto &i : points) {
            res.push_back(0);
            for (int y = i[1]; y < 101; y++) {
                if (r[y].empty()) continue;
                // for (auto &k : r[y]) cout << k << " "; cout << "\n";
                //all rectangles from rect[x] have their x coordinate >= i[0]
                int x = search(r[y], i[0]);
                res.back() += r[y].size() - search(r[y], i[0]);
                // cout << "y: " << y << ", r[y].size: " << r[y].size() << ", x: " << x << "\n";
            }
        }
        return res;
    }
};