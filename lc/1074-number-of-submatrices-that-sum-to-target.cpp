class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int line = matrix.size();
        int column = matrix[0].size() + 1;
        vector<vector<int>> sum(line, vector<int>(column, 0));
        
        for (int i = 0; i < line; i++){
            for (int j = 1; j < column; j++){
                sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
            }
        }
        
        for (int start = 0; start < column; start++){
            for (int end = start + 1; end < column; end++ ){
                int sumOfSubMatrix = 0;
                unordered_map<int, int> map;
                map[0] = 1;
                
                for(int l = 0; l < line; l++){
                    sumOfSubMatrix += sum[l][end] - sum[l][start];
                    if (map.find(sumOfSubMatrix - target) != map.end())
                        count += map[sumOfSubMatrix - target];
                    map[sumOfSubMatrix]++;
                }
            }
        }
        return count;
    }
};