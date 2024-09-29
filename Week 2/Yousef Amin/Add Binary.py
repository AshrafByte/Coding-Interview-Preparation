class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        first = ''
        second = ''
        
        if len(a)>len(b):
            first = b
            second = a
            
        else:
            first = a
            second = b
        
        added_zeros = len(second) - len(first)
        
        while added_zeros:
            first = '0'+first
            added_zeros -=1
        
        rem = 0
        res = ''
        
        for i in range(len(first)-1,-1,-1):
            if rem == 0:
                if first[i]+second[i] == '01' or first[i]+second[i] == '10':
                    res = '1' + res
                else:
                    res = '0' + res
                    rem = '1'
            else:
                if first[i]+second[i] == '01' or first[i]+second[i] == '10':
                    res = '0' + res   
                else:
                    res = '1'+res
        res = rem + res