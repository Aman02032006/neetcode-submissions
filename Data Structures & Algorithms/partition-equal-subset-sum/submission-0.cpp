class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;

        if (sum % 2) return false;

        int t = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(t + 1, false));
        dp[0][0] = true;
        if (nums[0] <= t) dp[0][nums[0]] = true;

        for (int i = 1 ; i < n ; i++) {
            for (int j = 0 ; j <= t ; j++) {
                if (dp[i - 1][j]) {
                    dp[i][j] = true;
                    if (j + nums[i] <= t) {
                        dp[i][j + nums[i]] = true;
                        if (j + nums[i] == t) return true;
                    }
                }
            }
        }

        return false;
    }
};
