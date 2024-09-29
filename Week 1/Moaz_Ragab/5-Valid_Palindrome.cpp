class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                ans += tolower(s[i]);
            }

        }
        n = ans.size();
        cout << ans << endl;
        for (int i = 0; i < n / 2; i++) {
            if (ans[i] != ans[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};