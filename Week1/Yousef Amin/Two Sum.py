class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        my_dic = {}
        
        for index,num in enumerate(nums):
            if target-num in my_dic:
                return [my_dic[target-num],index]
            my_dic[num] = index

