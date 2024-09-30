class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, mini = 1e9;
        for (auto &price : prices)
        {
            mini = min(mini, price);
            profit = max(profit, price - mini);
        }
        return profit;
    }
};