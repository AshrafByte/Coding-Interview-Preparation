//
// Created by Ahmed hesen on 10/7/2024.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bprice = prices[0],profit=0;
        for(int price : prices){
            if(price - bprice > profit) profit = price - bprice;
            if(price < bprice) bprice = price;
        }
        return profit;
    }
};