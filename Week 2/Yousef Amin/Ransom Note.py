class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        
        my_dic = {}
        for char in magazine:
            if char not in my_dic:
                my_dic[char] = 1
            else:
                my_dic[char]+=1
        
        for char in ransomNote:
            if char not in my_dic or my_dic[char]==0:
                return False
            else:
                my_dic[char]-=1
        return True

