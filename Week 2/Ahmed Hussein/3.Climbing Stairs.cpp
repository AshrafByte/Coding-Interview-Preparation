//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    int climbStairs(int n) {

        int prev1=1, prev2=1, res=1;
        for(; n > 1; n--){
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};