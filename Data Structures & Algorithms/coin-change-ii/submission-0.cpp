class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int a = amount;

        vector<vector<int>> dp(n + 1, vector<int>(a + 1, 0));

        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j <= a ; j++) {
                if (!j) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] += dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }

        return dp[n][a];
    }
};
