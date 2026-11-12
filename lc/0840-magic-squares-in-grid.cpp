class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        //sum of rows is equal and grid has numbers from 1-9 -> so total sum is 45
        //then each row / col / diaginal has sum = 15 and middle number = 5
        //and even numbers at corners and odds at edges is important 
        //middle is 5, which is odd, and to make sum = 15 for all row/col/diagonal
        //the pairs of numbers top-bottom, left-right, both dagonals are 1-9,2-8,3-7,4-6
        //and sum of all row/col/diagonal is 15 which is odd so 
        // e o e
        // o 5 o
        // e o e
        //and clockwise / anticlockwise the number are as 43816729 and a total of 8 different grid combinations exist
        string k = "43816729", l = "92761834";
        int res = 0;
        for (int i = 1; i < g.size() - 1; i++) {
            for (int j = 1; j < g[0].size() - 1; j++) {
                if(g[i][j] != 5) continue;
                //corner are even
                if(g[i-1][j-1] %2 != 0 || g[i+1][j-1] %2 != 0  ||
                g[i-1][j+1] %2 != 0 || g[i+1][j+1] %2 != 0 )
                {
                    continue;
                }
                
                //not-corner are odd
                if(g[i][j-1] %2 == 0 || g[i-1][j] %2 == 0  ||
                g[i][j+1] %2 == 0 || g[i+1][j] %2 == 0 )
                {
                    continue;
                }
                
                if ( (g[i-1][j-1] + g[i-1][j] + g[i-1][j+1]) != 15 ||  //row1
                    (g[i+1][j-1] + g[i+1][j] + g[i+1][j+1]) != 15 ||  //row2
                    (g[i-1][j-1] + g[i][j-1] + g[i+1][j-1]) != 15) //column 1
                {
                    continue;
                }
                
                res++;
            }
        }
        return res;
    }
};