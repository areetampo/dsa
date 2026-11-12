class Solution {
public:
  pair<int, pair<int, int>> manhattanDistance(vector<vector<int>>& p, int delIdx) {
    int n = p.size();
    int mxSum = INT_MIN, mnSum = INT_MAX, mxDiff = INT_MIN, mnDiff = INT_MAX;
    int mxSumIdx = -1, mnSumIdx = -1, mxDiffIdx = -1, mnDiffIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (i == delIdx) continue;
        int sum = p[i][0] + p[i][1];
        int diff = p[i][0] - p[i][1];
        if (sum > mxSum) {
            mxSum = sum;
            mxSumIdx = i;
        }
        if (sum < mnSum) {
            mnSum = sum;
            mnSumIdx = i;
        }
        if (diff > mxDiff) {
            mxDiff = diff;
            mxDiffIdx = i;
        }
        if (diff < mnDiff) {
            mnDiff = diff;
            mnDiffIdx = i;
        }
    }
    // cout << "mxSum: " << mxSum << " mnSum: " << mnSum << " mxDiff: " << mxDiff << " mnDiff: " << mnDiff << endl;
    // cout << "mxSumIdx: " << mxSumIdx << " mnSumIdx: " << mnSumIdx << " mxDiffIdx: " << mxDiffIdx << " mnDiffIdx: " << mnDiffIdx << endl;
    if (mxSum - mnSum > mxDiff - mnDiff) return { mxSum - mnSum, {mxSumIdx, mnSumIdx} };
    return { mxDiff - mnDiff, {mxDiffIdx, mnDiffIdx} };
  }
  int minimumDistance(vector<vector<int>>& p) {
      pair<int, pair<int, int>> x = manhattanDistance(p, -1);
      // cout << x.first << " " << x.second.first << " " << x.second.second << endl;
      return min(manhattanDistance(p, x.second.first).first, manhattanDistance(p, x.second.second).first);
  }
};