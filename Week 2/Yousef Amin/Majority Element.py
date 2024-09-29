class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        my_dic = {}
        for num in nums:
            if num not in my_dic:
                my_dic[num] = 1
            else:
                my_dic[num]+=1
        mx = 0
        terget = -1
        for k,v in my_dic.items():
            if v>mx:
                mx=v
                terget = k
        return terget

