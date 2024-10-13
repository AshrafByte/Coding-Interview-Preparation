//
// Created by Ahmed Hussein on 10/5/2024.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> mp(nums.size());
        for(int i=0; i<nums.size(); i++) mp[i] = {nums[i], i};

        sort(mp.begin(), mp.end());
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int sum = mp[start].first + mp[end].first;
            if(sum == target) break;
            else if(sum > target) end--;
            else start++;
        }
        return {mp[start].second, mp[end].second};
    }
};