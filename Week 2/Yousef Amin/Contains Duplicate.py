class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        my_dic = {}
        for num in nums:
            if num not in my_dic:
                my_dic[num]=1
                continue
            my_dic[num]+=1
        
        for value in my_dic.values():
            if value>1:
                return True
        return False

