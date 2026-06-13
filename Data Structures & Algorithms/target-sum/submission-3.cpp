class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int m = accumulate(nums.begin(), nums.end(), 0);

        if (target > m || target < -m) return 0;

        cout << m << endl;

        vector<vector<int>> dp(n + 1, vector<int>(2 * m + 1, 0));
        dp[0][m] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -m; j <= m; j++) {
                if (dp[i - 1][j + m]) {
                    dp[i][j + nums[i - 1] + m] += dp[i - 1][j + m];
                    dp[i][j - nums[i - 1] + m] += dp[i - 1][j + m];
                }
            }
        }

        return dp[n][target + m];
    }
};
