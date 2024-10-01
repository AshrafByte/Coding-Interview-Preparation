#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> cnt;
        for (auto i: s) {
            cnt[i]++;
        }
        int ans = 0, odd = 0;
        for (auto x: cnt) {
            if (x.second & 1) {
                odd = 1;
                ans += x.second - 1;
            } else ans += x.second;
        }
        return ans + odd;
    }
};