class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;
    int highestFreq = 0;
    for (char &c : tasks) { ++mp[c]; highestFreq = max(highestFreq, mp[c]); }
    int mxFreqChars = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (it->second == highestFreq) ++mxFreqChars;
    }
    return max((int)tasks.size(), highestFreq * (n + 1) - (n + 1 - mxFreqChars));
  }
  //weird question
  //(place highest freq char and put n slots next) do this the highest freq number of times
  //then keep putting other chars eg: 3a 3b cdefghijk n = 7, after a.. n places (gaps) to fill
  //abcdefg
  //abhijk???
  //ab??????? these last question marks eliminated
  //calc last question marks is arg2 of return max()
  //arg1 is all chars filled with no idle spaces
  //eg: 6a bcdefgh n = 1
  //a b
  //a c
  //a d
  //a e
  //a f
  //a g
  //now h can just be placed with no issue so total len = tasks.len
};