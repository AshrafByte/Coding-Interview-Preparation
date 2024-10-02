#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int start = 0; 
        unordered_map<char, int> cnt; 
        for (int i = 0; i < s.size(); i++) {
           
            if (cnt.find(s[i]) != cnt.end() && cnt[s[i]] >= start) {
                start = cnt[s[i]] + 1;
             
            }
       
            ans = max(ans, i - start + 1);
         
            cnt[s[i]] = i;
        }
        return ans;
    }
};
