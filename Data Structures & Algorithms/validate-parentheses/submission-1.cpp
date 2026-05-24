class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        bracket.push(s[0]);

        for (int i = 1 ; i < s.size() ; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') bracket.push(s[i]);
            else if (s[i] == ')') {
                if (!bracket.empty() && bracket.top() == '(') bracket.pop();
                else return false;
            }
            else if (s[i] == '}') {
                if (!bracket.empty() && bracket.top() == '{') bracket.pop();
                else return false;
            }
            else if (s[i] == ']') {
                if (!bracket.empty() && bracket.top() == '[') bracket.pop();
                else return false;
            }
        }

        if (bracket.empty()) return true;
        else return false;
    }
};
