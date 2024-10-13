//
// Created by Ahmed hesen on 10/7/2024.
//

class Solution {
public:
    bool isPalindrome(string s) {
        int r=0, l=s.size()-1;
        while(r < l){
            if(!isalnum(s[r])){
                r++;
                continue;
            }
            if(!isalnum(s[l])){
                l--;
                continue;
            }
            if(tolower(s[r]) != tolower(s[l])){
                return 0;
            }
            r++;
            l--;
        }
        return 1;
    }
};