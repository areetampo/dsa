class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        //at start mx = v[0] - 1 representing that when it will move to the next
        //index (lets say the next index = 1 is considered), the gap diff would
        //already be subtracted form mx, now res is calc by just sum of v[idx] 
        //and mx | now mx should be updated or not? it is carrying the value
        //from prev index - 1 (the gap right now) so choices are: this is carried
        //ahead that means just do - 1 from mx (so at index = 2 mx = v[0] - 2 OR
        //the current element v[1] is taken and since we are moving to the next
        //index the considered gap would be 1 again that means mx = v[1] - 1)
        //arr    4          6          4          8          5          5
        //idx    0          1          2          3          4          5
        //i = 0 -> v[i] = 4 so mx set to v[i] - 1 = 3
        //i = 1 -> res considered by adding v[i] + mx = 9 and
        //mx = max(curr mx which represents prev max value with gap until now
        //considered - 1 (since moving to next index), v[i] - 1) = max(3-1, 6-1) 
        //i = 2 -> res = max(res = 9, v[i] = 4 + mx = 5) = 9 and 
        //mx = max(mx (which is considered prev maximum value - gap from this
        //index to where mx is present) - 1 (cuz will be moving right 1 index)
        //, curr v[i] - 1 (as curr element considered but moving right)) = 
        //max(5 - 1, 4 - 1) = 4
        //i = 3 -> observe that max holds the max of v[0] - 3, v[1] - 2, v[2] - 1
        //so now again repeat the above steps
        int res = 0;
        for (int i = 1, mx = v[0] - 1; i < v.size(); i++) {
            res = max(res, v[i] + mx);
            mx = max(mx - 1, v[i] - 1);
        }
        return res;
    }
};