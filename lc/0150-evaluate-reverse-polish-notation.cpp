class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (string &x : tokens) {
            if (x != "+" && x != "-" && x != "*" && x != "/") {
                s.push(x);
            } else {
                int b = stoi(s.top()); s.pop();
                int a = stoi(s.top()); s.pop();
                if (x == "+") s.push(to_string(a + b));
                else if (x == "-") s.push(to_string(a - b));
                else if (x == "*") s.push(to_string(a * b));
                else s.push(to_string(a / b));
            }
        }
        return stoi(s.top());
    }
};