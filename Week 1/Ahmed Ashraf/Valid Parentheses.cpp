class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &ch : s)
        {
            bool isValid1 = false, isValid2 = false, isValid3 = false;

            if (!st.empty())
            {
                isValid1 = (st.top() == '(' && ch == ')');
                isValid2 = (st.top() == '[' && ch == ']');
                isValid3 = (st.top() == '{' && ch == '}');
            }

            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);

            else if (isValid1 || isValid2 || isValid3)
                st.pop();

            else
                return false;
        }
        return (st.size() == 0);
    }
};