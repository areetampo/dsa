class Solution {
public:
  int bagOfTokensScore(vector<int>& v, int power) {
    if (!v.size()) return 0;
    if (v.size() == 1) return power >= v[0];
    //approach: pick starting els (low power) to trade ur power and gain ++score
    //with each gained score, can trade powers from last and then
    //in the middle use gained power to gain scores adn maximise score
    //note: also keep track of scores at beginning when trading power to gain those scores
    sort(v.begin(), v.end());
    int score = 0, res = 0;
    int i = 0, j = v.size() - 1;
    while (i <= j) {
      if (power >= v[i]) {
        power -= v[i++];
        ++score;
        res = max(res, score);
      } else if (score) {
        --score;
        power += v[j--];
      } else break;
    }
    return res;
  }
};