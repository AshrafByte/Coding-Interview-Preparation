class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        first_dic = {}
        
        for char in s:
            if char not in first_dic:
                first_dic[char] = 1
                
            else:
                first_dic[char]+=1
        
        second_dic = {}
        
        for char in t:
            if char not in second_dic:
                second_dic[char] = 1
                
            else:
                second_dic[char]+=1

        
        for key,value in first_dic.items():
            if key not in second_dic or second_dic[key] != value:
                return False
            
        for key,value in second_dic.items():
            if key not in first_dic or first_dic[key] != value:
                return False
        
        return True

sol = Solution()
print(sol.isAnagram('a', 'ab'))