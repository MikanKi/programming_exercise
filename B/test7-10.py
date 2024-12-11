class Stack:
    def __init__(self):
        self.list = []
    
    def push(self,item):
        self.list.append(item)
    
    def pop(self):
        if len(self.list)==0:
            print(None)
        else:
            last = self.list[-1]
            del self.list[-1]
            print(last)
    
    def peek(self):
        print(self.list[-1])
    
    def out(self):
        print(self.list)

s = Stack()
s.push(0)
s.out()
s.push(1)
s.push(2)
s.out()
s.pop()
s.out()
s.peek()
s.out()
