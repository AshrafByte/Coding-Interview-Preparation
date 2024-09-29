class Solution {
public:
    bool isValid(string s) {
    stack<char> myStack;
    for(int i=0;i<=s.length();++i){
            if(s[i] == '(' || s[i] ==')'|| s[i] == '{'|| s[i] == '}' || s[i] == '[' || s[i] == ']'){
                if(myStack.empty()){
                    myStack.push(s[i]);
                }
                else if((s[i] == ')' && myStack.top() == '(') ||
                    (s[i] == '}' && myStack.top() == '{') ||
                    (s[i] == ']' && myStack.top() == '[')){
                    myStack.pop();
                }
                else{
                    myStack.push(s[i]);
                }
            }
        }
        return myStack.empty();
    }
};