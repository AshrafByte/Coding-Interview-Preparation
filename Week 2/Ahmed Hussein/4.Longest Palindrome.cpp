//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(char c: s) map[c]++;
        int res=0;
        for(auto i: map){
            res += (i.second/2)*2;
        }
        if( !(res & 1) && res<s.size()) return res+1;
        else return res;
    }
};