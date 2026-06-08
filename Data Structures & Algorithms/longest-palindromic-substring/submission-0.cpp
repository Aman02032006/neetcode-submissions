class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int idx = 0, len = 0;
        for (int i = n - 1; i >= 0 ; i--) {
            for (int j = i ; j < n ; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > len) {
                        len = j - i + 1;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, len);
    }
};
