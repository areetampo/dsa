class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& g) {
        //there can only elemnt as answer
        //eg:
        //let A and D be lucky numbers, cant be in same row or same col obviously so:
        //A --- B
        //|     |
        //C-----D now according to conditions, A and D min in row and max in their respective col, so:
        //A < B, A > C --> C < A < B, and
        //D < C, D > B --> B < D < C, which contradicts he above statement
        //so both minMax and maxMin must be equal otherwise no answer possible
        int m = g.size();
        int n = g[0].size();
        
        int maxMin = INT_MIN;//out of all minimum elemnts of all rows, max of those
        for (int i = 0; i < m; i++) {
            int min = INT_MAX;
            for (int j = 0; j < n; j++)
                min = std::min(min, g[i][j]);
            maxMin = std::max(maxMin, min);
        }

        int minMax = INT_MAX;//out of all max elemnts of all cols, min of those
        for (int j = 0; j < n; j++) {
            int max = INT_MIN;
            for (int i = 0; i < m; i++)
                max = std::max(max, g[i][j]);
            minMax = std::min(minMax, max);
        }
        
        if (maxMin != minMax) return vector<int> { };
        return vector<int> { maxMin };
    }
};