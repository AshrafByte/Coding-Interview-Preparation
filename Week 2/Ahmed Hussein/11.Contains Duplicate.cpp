//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int n: nums){
            if(map[n]++ > 0) return true;
        }
        return false;
    }
};