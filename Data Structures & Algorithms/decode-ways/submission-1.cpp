class Solution {
    int pairToNum(char a, char b) {
        return 10 * (a - '0') + (b - '0');
    }
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            else {
                dp[i] = dp[i + 1];
                if (i == n - 1) continue;
                int k = pairToNum(s[i], s[i + 1]);
                if (k >= 10 && k <= 26) dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
