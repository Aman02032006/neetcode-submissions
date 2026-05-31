class Solution {
    vector<vector<char>> chars = {{}, 
                                  {}, 
                                  {'a', 'b', 'c'}, 
                                  {'d', 'e', 'f'}, 
                                  {'g', 'h', 'i'},
                                  {'j', 'k', 'l'},
                                  {'m', 'n', 'o'},
                                  {'p', 'q', 'r', 's'},
                                  {'t', 'u', 'v'}, 
                                  {'w', 'x', 'y', 'z'}};

    vector<string> res;

    void backtrack(int i, string curr, string digits) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }

        for (char ch : chars[digits[i] - '0']) {
            backtrack(i + 1, curr + ch, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()) backtrack(0, "", digits);

        return res;
    }
};
