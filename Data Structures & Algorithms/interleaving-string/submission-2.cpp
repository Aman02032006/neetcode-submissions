class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (s3.size() != m + n) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s1[i] == s3[i + m]) dp[i][m] = dp[i + 1][m];
        }
        
        for (int j = m - 1; j >= 0; j--) {
            if (s2[j] == s3[n + j]) dp[n][j] = dp[n][j + 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s3[i + j]) dp[i][j] = dp[i + 1][j];
                if (s2[j] == s3[i + j]) dp[i][j] = dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
