//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> map;
        int major = nums.size()/2, ans=0;
        for(int num: nums) {
            map[num]++;
            if(map[num] > major){
                ans=num;
                return num;
            }
        }
        return ans;
    }
};