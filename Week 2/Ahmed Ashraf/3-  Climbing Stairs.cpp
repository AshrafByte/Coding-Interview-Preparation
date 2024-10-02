class Solution {
public:
    unordered_map <int,int> ways ;
    int climbStairs(int n) 
    {
        if (n <= 0)
            return (n == 0) ;
        
        if (ways.count(n) == 0)
            ways[n] = climbStairs(n-1) + climbStairs(n-2);

        return ways[n];
    }
    
};
