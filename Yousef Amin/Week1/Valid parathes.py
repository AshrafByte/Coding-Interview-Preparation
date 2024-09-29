class Solution:
    def isValid(self, name) :
        my_dic = {
            ')': '(',
            '}': '{',
            ']': '['
        }
        
        arr = []
        for char in name:
            if char in my_dic: 
                if arr and arr[-1] == my_dic[char]:  
                    arr.pop() 
                else:
                    return False  
            else:
                arr.append(char)  
        
        return not arr 
