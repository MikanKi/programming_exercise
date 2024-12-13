import numpy as np

ma = np.array([[1,3,5],[7,11,13],[17,19,23]])
ima = np.linalg.inv(ma)

print(ima)
print(ima.dot(ma))
print(ma.dot(ima))
for i, c in enumerate(range(ord('a'), ord('z') + 1)):
    print(i,c)
