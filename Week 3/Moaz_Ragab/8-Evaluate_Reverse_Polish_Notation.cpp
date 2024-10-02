class Solution {
public:
    int evalRPN(vector <string> &tokens) {
        stack<int> ans;
        for (int i = 0; i < tokens.size(); i++) {
            char c = tokens[i][0];
            int nu;
            if (c != '/' && c != '+' && (c != '-' || tokens[i].size() > 1) && c != '*') {
                int tmp = stoi(tokens[i]);
                ans.push(tmp);

            } else {
                if (ans.size() == 1)
                    continue;
                int x = ans.top();
                ans.pop();
                int y = ans.top();
                ans.pop();
                if (c == '/') {
                    nu = y / x;

                } else if (c == '*') {
                    nu = y * x;

                } else if (c == '+') {
                    nu = y + x;

                } else {
                    nu = y - x;

                }
                ans.push(nu);
            }

        }
        return ans.top();
    }
};