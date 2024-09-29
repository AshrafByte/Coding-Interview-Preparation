class MyQueue(object):

    def __init__(self):
        self.lst = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.lst.append(x)

    def pop(self):
        """
        :rtype: int
        """
        stack = []
        value = None
        
        while self.lst:
            value = self.lst.pop()
            stack.append(value)
        
        stack.pop()
        
        while stack:
            self.lst.append(stack.pop())
        
        return value

    def peek(self):
        """
        :rtype: int
        """
        stack = []
        value = None
        
        while self.lst:
            value = self.lst.pop()
            stack.append(value)
        
        
        while stack:
            self.lst.append(stack.pop())
        
        return value

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.lst) == 0


