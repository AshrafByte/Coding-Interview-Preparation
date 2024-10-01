class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = 0, tmp = -1e6;
        for (auto i: nums) {
            if (ans < 0)
                ans = i;
            else
                ans += i;
            if (ans > tmp) {
                tmp = ans;
            }

        }
        return tmp;
    }
};