import csv
f = open("Sample1.csv","w")

w = csv.writer(f)

w.writerow(["tokyo","eraser"])
w.writerows([["tokyo","ruler"],["nagoya","notebook"]])
f.close()
