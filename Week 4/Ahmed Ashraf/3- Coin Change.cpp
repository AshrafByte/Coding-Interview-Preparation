class Solution
{
    // dynamic programming.
    /*
        get the min number of coins needed each amount less than the required amount,
        then use them to calculate the min number of coins needed for the required amount.
        EX : if we have coins [1,2,5] and the required amount is 11.
        one possible way to get the min number of coins that make 11 is by taking one coin of [1],
        and using the min number of coins needed for the remaining (11 - 1 = 10).
        and we will do the same with amount = 10 till we find the min.
    */
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
            for (auto coin : coins)
                if (i >= coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};