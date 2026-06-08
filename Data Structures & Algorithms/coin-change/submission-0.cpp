class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t = amount;

        vector<int> dp(t + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1 ; i <= t ; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[t] == INT_MAX ? -1 : dp[t]);
    }
};
