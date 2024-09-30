class Solution
{
public:
    bool isPalindrome(string s)
    {
        string converted;
        for (auto &ch : s)
            if (isalnum(ch))
                converted += tolower(ch);

        int left = 0;
        int right = converted.length() - 1;
        while (left <= right)
            if (converted[left++] != converted[right--])
                return false;

        return true;
    }
};

//////////////////////////////////////////////////////////////
// another solution better for saving more space.

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left <= right)
        {
            char leftCh = tolower(s[left]);
            char rightCh = tolower(s[right]);

            if (!isalnum(leftCh))
            {
                left++;
                continue;
            }

            if (!isalnum(rightCh))
            {
                right--;
                continue;
            }

            if (leftCh != rightCh)
                return false;

            left++;
            right--;
        }
        return true;
    }
};