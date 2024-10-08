class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        stack = []
        
        for char in s:
            
            if char != ']':
                stack.append(char)
            
            else:
                
                if stack and stack[-1]=='[':
                    stack.pop()
                
                else:
                    stack.append(char)
        
        x = len(stack)/2
        
        return (x+1)//2