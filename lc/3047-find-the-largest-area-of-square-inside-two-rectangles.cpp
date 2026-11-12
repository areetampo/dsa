class Solution {
public:
  long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
    int n = bl.size();
    int res = 0; // side len
    for (auto i = 0; i < n - 1; ++i) {//rect a
      for (auto j = i + 1; j < n; ++j) {//rect b
        int alx = bl[i][0];//rect a's left x coordinate
        int arx = tr[i][0];//rect a's right x coordinate
        int blx = bl[j][0];//rect b's left x coordinate
        int brx = tr[j][0];//rect b's right x coordinate
        int aby = bl[i][1];//rect a's bottom y coordinate
        int aty = tr[i][1];//rect a's top y coordinate
        int bby = bl[j][1];//rect b's bottom y coordinate
        int bty = tr[j][1];//rect b's top y coordinate
        int highX = min(arx, brx);
        int lowX = max(alx, blx);
        int highY = min(aty, bty);
        int lowY = max(aby, bby);
        res = max(res, min(highX - lowX, highY - lowY));//if -ve, res stays 0
      }
    }
    return (long long) res * res;
  }
};