class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        s = ''.join(item for item in s if item.isalnum())
        s = s.lower()
        
        return s == s[::-1]