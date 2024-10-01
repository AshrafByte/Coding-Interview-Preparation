class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {


        unordered_map<char,int>mag;
        int n=ransomNote.size();
        int m=magazine.size();
        for(auto t:magazine)
        {
            mag[t]++;

        }
        for(auto t:ransomNote)
        {
            if(mag[t]<=0)
            {
                return false;
            }
            mag[t]--;
        }
        return true;
    }
};