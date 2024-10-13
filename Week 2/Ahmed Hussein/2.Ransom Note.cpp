//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int>map;
        for(char i : magazine){
            map[i]++;
        }
        for(char i : ransomNote){
            if(map[i] <= 0)return 0;
            else map[i]--;
        }
        return 1;
    }
};