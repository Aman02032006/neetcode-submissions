class Solution {
    vector<string> res;

    void backtrack(string curr, int n, int open, int close) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) backtrack(curr + '(', n, open + 1, close);
        if (close < open) backtrack(curr + ')', n, open, close + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, 0, 0);
        return res;
    }
};
