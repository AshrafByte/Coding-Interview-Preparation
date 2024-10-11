class Solution {
public:
    bool wordBreak(string s, vector <string> &wordDict) {

        int n = s.size();
        int m = wordDict.size();
        vector<int> dp(n + 1, -1);
        function<bool(int)> go = [&](int i) -> bool {
            if (i == n) return true;
            if (~dp[i]) return dp[i];
            bool ans = false;
            for (int j = 0; j < m; j++) {
                int sz = wordDict[j].size();
                string tmp = s.substr(i, sz);
                if (tmp == wordDict[j]) {
                    ans = ans | go(i + sz);
                }
            }
            return dp[i] = ans;


        };

        return go(0);
    }
};