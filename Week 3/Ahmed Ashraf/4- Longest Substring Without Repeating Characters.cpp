class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map <char,int> freq ;

        int left = 0;
        int length = 0;
        for (int right = 0 ; right < s.length() ; right++)
        {
            if (freq[s[right]] == 0)
                length = max(length , right - left + 1 );
            
            while (freq[s[right]] != 0)
            {
                freq[s[left]]--;
                left++;
            }
            
            freq[s[right]]++;
        }
        return length;
    }
};