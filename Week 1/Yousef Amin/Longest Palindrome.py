class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        my_dic = {}

        for char in s:
            my_dic[char] = 1+my_dic.get(char,0)
        
        flag_odd = False
        s = 0

        for k,v in my_dic.items():
            if v %2 == 0:
                s +=v
            
            else:
                flag_odd = True
                s += (v-1)
        
        if flag_odd:
            return s+1
        return s