class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, vector<int>> indicies;
        for (int i = 0; i < nums.size(); i++) {
            indicies[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, sum = 0;
        while (left <= right) {
            sum = nums[right] + nums[left];
            if (sum == target)break;
            if (sum > target)right--;
            else left++;

        }
        vector<int> ans;
        ans.push_back(indicies[nums[left]].back());
        indicies[nums[left]].pop_back();
        ans.push_back(indicies[nums[right]].back());
        return ans;
    }
};