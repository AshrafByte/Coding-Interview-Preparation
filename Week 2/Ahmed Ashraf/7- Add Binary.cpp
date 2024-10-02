class Solution
{
public:
    map<string, char>
        mapAdd{{"000", '0'}, {"001", '1'}, {"011", '0'}, {"111", '1'}},
        mapCarry{{"000", '0'}, {"001", '0'}, {"011", '1'}, {"111", '1'}};
    string addBinary(string a, string b)
    {
        // Padding so that the 2 strings become equal in length.
        if (a.length() < b.length())
            a.insert(a.begin(), b.length() - a.length(), '0');

        if (a.length() > b.length())
            b.insert(b.begin(), a.length() - b.length(), '0');

        int length = a.length();
        char carry = '0';

        string ans = a;
        for (int i = length - 1; i >= 0; i--)
        {
            string sum;
            sum += a[i];
            sum += b[i];
            sum += carry;

            sort(sum.begin(), sum.end());

            ans[i] = mapAdd[sum];
            carry = mapCarry[sum];
        }
        if (carry == '1')
            ans = carry + ans;
        return ans;
    }
};