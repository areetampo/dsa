class Solution {
public:
    long long findScore(vector<int>& v) {
        //note: 'considered' in the below para referes to adding el in score
        //below commented approach fails for [1854,1642,1524,413,10]
        //the logic is that if in a window of size = 3 off unmarked elements,
        //the minimum element will be taken into consideration (added to score)
        //at some point if its not marked as an adjacent element already
        //(means its adjacent elements are greater than it so next time a min
        //unmarked element is to be considered it will be this only)
        //in that appraoch each time a size = 3 window of next unmarked elements
        //is considered and if the first or second elmenent is min then its 
        //marked along with adjacent elements cuz they would always be considered
        //by pq and their score is selected
        //the problem arrives if the minimum element is the third because then
        //lets say case 1: its marked, then adj left element is also marked,
        //remains the first element [...5 4 3...] -> score += 3 and 3, 4 marked
        //so 5 would definitely be added to score at some point as will be the
        //smallest unmarked element but the problem arrives what if 4 could be
        //marked (so 5 and 3 get marked and we can move to right after 3) but that
        //is only possible if 4 gets considered before 3 (which means 3 has to
        //already be marked which is only possible if there is a el smaller than
        //3 to its right as that would be considered cuz for 3 to be marked
        //without getting added to score, would be that a element smaller then 3
        //is considered and 3 gets marked as an adj el)
        //so that way later 4 is considered (added to score) and 5 gets marked too
        //but what if there is even a smaller elemnet to right?
        //eg: [...5 4 3 2 1] then 1 will get added to score, marking 2 as well
        //tehn 3 must be added to score marking 4 and then 5 will be added to score
        //the problem here is if there is a decreasing sequence then the minimum
        //el gets considered then its left adj gets marked
        //every time the minimum unmarked el is considered and marked along with
        //its adj els, so element 2 steps back of it in the dec seq gets
        //considered afterwards and so on...
        //so with that out of the way, now lets say the current el we are on is
        //<= to next element that means if a pq was used that element would
        //get considered and the element to its right will get marked 
        int n = v.size();
        if (n == 1) return v[0];
        long long res = 0;
        for (int i = 0; i < n; ) {
            if (i + 1 < n && v[i] <= v[i + 1]) {
                res += v[i];
                i += 2;
            } else {
                int j = i;
                while (j + 1 < n && v[j] > v[j + 1]) j++;
                for (int k = j; k >= i; k -= 2) res += v[k];
                i = j + 2;
            }
        }
        return res;
    }
};
// long long res = 0;
// for (int i = 0; i < v.size(); ) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
//     for (int j = 0; j < 3 && i + j < v.size(); j++) {
//         p.push({v[i + j], i + j});
//     }
//     int min = p.top().first, idx = p.top().second;
//     cout << min << " " << idx << " . ";
//     if (idx == i + 2) {
//         p.pop();
//         if (i + 3 < v.size() && v[i + 2] > v[i + 3]) {
//             min = p.top().first, idx = p.top().second;
//             p.pop();
//             if (min >= p.top().first) {
//                 //if new min update idx otherwise pq had min idx already
//                 if (min > p.top().first) idx = p.top().second;
//                 min = p.top().first;
//             }
//             // if (p.top().second != i + 1) p.pop();
//             // min = p.top().first, idx = p.top().second;
//         } else {
//             if (p.top().second != i) p.pop();
//             min = p.top().first, idx = p.top().second;
//         }
//         cout << min << " " << idx << " ";
//         res += min;
//         i += 2;
//     } else {
//         res += min;
//         i = idx + 2;
//     }
//     cout << "| " << res << "\n";
// }
// return res;