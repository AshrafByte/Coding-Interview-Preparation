class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {

        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int x = nums[i];
                int y = nums[j];
                int z = -(x + y);
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), z);
if (it != nums.end() && *it == z) {
                    int mn = min({x, y, z});
                    int mx = max({x, y, z});
                    int mn2 = x + y + z - mn - mx;

                    if (mp.find({mn, mn2}) == mp.end()) {
                        ans.push_back({mn, mn2, mx});
                        mp[{mn, mn2}] = 1;
                    }
                }
            }
        }
        return ans;
    }
};