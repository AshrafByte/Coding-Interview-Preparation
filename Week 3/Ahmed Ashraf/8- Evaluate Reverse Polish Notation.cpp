class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for (auto &token : tokens)
        {
            if (!(token == "/" || token == "-" || token == "+" || token == "*"))
                st.push(stoi(token));
            else
                st.push(doOperation(st,token));
        }
        return st.top();
    }
    int doOperation(stack<int> &st , string op)
    {
        int num2 = st.top(); st.pop();
        int num1 = st.top(); st.pop();

        char operation = op[0];
        switch (operation)
        {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '/': return num1 / num2;
        case '*': return num1 * num2;  
        }
        
        return -1;
    }
};