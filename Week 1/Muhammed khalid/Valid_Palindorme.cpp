class Solution {
public:
    bool isPalindrome(string s) {
        string front,back;
         int start =0;
         int end =s.size()-1;
        while ((start<s.size()) && end>=0){
            if(isalnum(s[start])) front+=tolower(s[start]);
            if(isalnum(s[end]))back+= tolower(s[end]);
            start++;
            end--;
        }
        return front.compare(back) == 0 ? true : false;
    }
};
