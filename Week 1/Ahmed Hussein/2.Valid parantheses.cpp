//
// Created by Ahmed hesen on 10/7/2024.
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if (st.empty() || (ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '[')) {
                    return 0;
                }

                else st.pop();
            }
        }
        if(st.empty())return 1;
        else return 0;
    }
};