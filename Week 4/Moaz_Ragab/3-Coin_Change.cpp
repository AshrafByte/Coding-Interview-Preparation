//dp recursive solution
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        int sz = coins.size();
        vector<long long> dp(10000 + 5, -1);
        function<long long(long long)> go = [&](long long sum) -> long long {

            if (sum == amount)return 0;
            auto &ret = dp[sum];
            if (ret != -1)
                return ret;
            long long ans = 1e9;
            for (int i = 0; i < sz; i++) {
                if ((sum + coins[i]) <= amount) {
                    ans = min(ans, 1 + go(sum + coins[i]));

                }
            }

            return dp[sum] = ans;

        };
        int ans = go(0);
        if (ans == 1e9)
            return -1;

        return ans;
    }
}; 
//dp iterative solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;        
    }
};