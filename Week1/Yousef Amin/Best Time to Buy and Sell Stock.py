class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        left = 0
        right = 1
        
        if len(prices)==1:
            return 0
        
        elif len(prices)==2:
            mx_profit = prices[right]-prices[left] if prices[right]>prices[left] else 0
            
        else:
            mx_profit=0
            
            for i in range(1,len(prices)):
                
                profit = prices[right]-prices[left]
                
                if profit<=0:
                    left = right
                    right+=1
                    
                elif (profit>0):
                    right+=1
                    mx_profit = max(profit,mx_profit)
                        
        return mx_profit
