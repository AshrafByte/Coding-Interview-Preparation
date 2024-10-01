class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> cnt;
        int ans = 0, elem;
        for (auto x: nums) {
            int tmp = ++cnt[x];
            if (tmp > ans) {
                ans = tmp;
                elem = x;
            }

        }
        return elem;
    }
};