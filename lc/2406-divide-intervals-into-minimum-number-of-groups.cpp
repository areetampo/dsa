class Solution {
public:
    int minGroups(vector<vector<int>>& v) {
        //initial thought (nlogn) binary search using vector of lists
        //sort -> (lexicographical)
        //(1, 5) (1, 10), (2, 3), (5, 10), (6, 8)
        //iterate
        //interval 1
        //(1, 5)
        //interval 2 [binary search on ending prev positions to find largest
        //end value < curr's start -> add in list]
        //{note: largest impo cuz its most beneficial to add curr pair in this group (list) of pairs
        //so the otehr groups with much smaller end pair is reserved for other pairs to be put if
        //they arent able to be put in groups with larger end val (group end > curr pair's end)}
        //otherwise create new list {READ ABOUT THE BINARY SEARCH ISSUE BELOW}
        //(1, 5) | (1, 10)
        //interval 3
        //(1, 5) | (1, 10) | (2, 3)
        //interval 4
        //(1, 5) | (1, 10) | (2, 3), (5, 10)
        //interval 5
        //(1, 5), (6, 8) | (1, 10) | (2, 3), (5, 10)
        //ISSUE -> FOR EACH NEW LIST CREATED IT MUST BE PUT IN SUCH A WAY THAT THE LAST PAIR'S
        //END OF ALL LISTS ARE SORTED -> SO USING A MIN HEAP WITH JUST THE ENDS IS EASIER APPROACH
        //AND EACH TIME PQ.TOP WILL GIVE MIN ELEMENT SO ADD CURR'S END IN PQ IN END PQ WILL
        //HAVE ALL DIFFERENT GROUP'S ENDS -> PQ.SIZE == TOTAL GROUPS
        sort(begin(v), end(v));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : v) {
            if (!pq.empty() && pq.top() < i[0])
                pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};