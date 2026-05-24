class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op2 = eval.top();
                eval.pop();
                int op1 = eval.top();
                eval.pop();
                int val = (s == "+") ? op1 + op2 : ((s == "-") ? op1 - op2 : ((s == "*") ? op1 * op2 : ((s == "/") ? op1 / op2 : 0)));
                eval.push(val);
            }
            else eval.push(stoi(s));
        }

        return eval.top();
    }
};
