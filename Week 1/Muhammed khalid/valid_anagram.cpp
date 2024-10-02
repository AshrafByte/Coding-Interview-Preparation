class Solution {
public:
    bool isAnagram(string s, string t) {
        int pos ;
        if(s.length() !=t.length()) return false;
        else{
            for(int i=0;i<s.size();++i){
                pos = t.find(s[i]);
                if( t.find(s[i]) == string::npos) return false;
                else t.erase(pos,1);
            }
            return t.empty();
        }
    }
};
