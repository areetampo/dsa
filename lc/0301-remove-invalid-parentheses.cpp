class Solution {
  set<string> validExpressions;
  int minimumRemoved;

  void reset() {
    validExpressions.clear();
    minimumRemoved = INT_MAX;
  }

  void recurse(
      string& s,
      int index,
      int leftCount,
      int rightCount,
      string& expression,
      int removedCount) {

    // Reached the end of the string.
    if (index == (int)s.size()) {
      // Valid if number of '(' and ')' are equal.
      if (leftCount == rightCount) {
        if (removedCount <= minimumRemoved) {
          string possibleAnswer = expression;

          // Found a better answer, discard previous answers.
          if (removedCount < minimumRemoved) {
            validExpressions.clear();
            minimumRemoved = removedCount;
          }

          validExpressions.insert(possibleAnswer);
        }
      }
      return;
    }

    char c = s[index];
    int length = expression.size();

    // Non-parenthesis characters are always kept.
    if (c != '(' && c != ')') {
      expression += c;
      recurse(s, index + 1, leftCount, rightCount,
              expression, removedCount);
      expression.resize(length);
    } else {

      // Option 1: remove this parenthesis.
      recurse(s, index + 1, leftCount, rightCount,
              expression, removedCount + 1);

      // Option 2: keep this parenthesis.
      expression += c;

      if (c == '(') {
        recurse(s, index + 1, leftCount + 1, rightCount,
                expression, removedCount);
      } 
      else if (rightCount < leftCount) {
        // A ')' can only be kept if there is an unmatched '('.
        recurse(s, index + 1, leftCount, rightCount + 1,
                expression, removedCount);
      }

      // Undo the append.
      expression.resize(length);
    }
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    reset();

    string expression;
    recurse(s, 0, 0, 0, expression, 0);

    return vector<string>(validExpressions.begin(),
                          validExpressions.end());
  }
};