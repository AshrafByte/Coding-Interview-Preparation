class Solution {
public:
    int x;

    int climbStairs(int n) {
        x = n;
        memset(dp, -1, sizeof dp);
        return cm(0);
    }

    int dp[46];

    int cm(int i) {
        if (x == i) return 1;

        if (~dp[i])return dp[i];
        dp[i] = 0;
        dp[i] = cm(i + 1);
        if (i + 2 <= x) {
            dp[i] += cm(i + 2);
        }
        return dp[i];
    }
};