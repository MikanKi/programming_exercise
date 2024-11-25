class Triangle:
    def __init__(self, line1, line2, line3):
        self.line1 = line1
        self.line2 = line2
        self.line3 = line3

    def is_valid(self):
        return self.line1 > 0 and self.line2 > 0 and self.line3 >0 and \
        self.line1 + self.line2 > self.line3 and \
        self.line2 + self.line3 > self.line1 and \
        self.line3 + self.line1 > self.line2
    
    def area(self):
        if not self.is_valid():
            return 0
        return self.calculate_area_helons_formula()
    
    def calculate_area_helons_formula(self):
        s = (self.line1 + self.line2 + self.line3)/2
        return (s*(s-self.line1)*(s-self.line2)*(s-self.line3)) ** 0.5

t1 = Triangle(3, 4, 5)
assert t1.is_valid(), "有効な三角形であるはずです．"
assert t1.area() == 6.0, "面積は 6.0 であるはずです．"

t2 = Triangle(1, 1, 3)
assert not t2.is_valid(), "有効な三角形ではないはずです．"
assert t2.area() == 0, "面積は 0 であるはずです．"
