class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (auto i: nums) {
            cnt[i]++;
            if (cnt[i] > 1)
                return true;
        }
        return false;
    }
};