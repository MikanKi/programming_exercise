class Person:
    def __init__(self,name,age):
        self._name = name
        self._age = age
    
    def __format__(self):
        return f"{self._name} is {self._age} years old."
    
    def __str__(self):
        return f"{self._name} is {self._age} years old."