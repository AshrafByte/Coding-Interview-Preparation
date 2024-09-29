class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=1e9;
        for(int i=0;i<prices.size();i++)
        {
        
            mn=min(mn,prices[i]);
            int diff=prices[i]-mn;
                ans=max(ans,diff);
        }
        return ans;
    }
};