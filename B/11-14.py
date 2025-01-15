"""
vector
"""
#don't forget to import numpy for vector and matrix
import numpy as np

#np.array for vector, write vector as list
a = np.array([1,2,3])
b = np.array([1,2,3])
#use normal arithmetics for +, - and *(scalar)

#size of vector, not length
len(a)

#dot multiplication of vectors
a.dot(b)
np.inner(a,b)

#length of vector
np.linalg.norm(a)

#formula for cosine similarity = (v1・v2)/|v1|*|v2|
a.dot(b)/(np.linalg.norm(a)*np.linalg.norm(b))


"""
matrix
"""
#for matrix, list inside of a list
ma = np.array([[1,2,3],[4,5,6],[7,8,9]])
mb = np.array([[9,8,7],[6,5,4],[3,2,1]])
# 1 2 3
# 4 5 6
# 7 8 9

#first digit is row, second digit is column
ma[1][0]

#multiplication using dot
ma.dot(mb)
#order is important for matrix

#.identity(n) for identity matrix, n is size of matrix
mi = np.identity(3)

#inverse of matrix
ima = np.linalg.inv(ma)


"""
machine learning
"""
#generates a vector with size n full of 0s
np.zeros(10)

#same as zeros, but with 1s instead
np.ones(10)

#makes a 3D matrix 2x3x4, dimensions should be tuple
a1 = np.zeros((2,3,4))

#changes the dimensions of a matrix, but has to keep the same size
np.reshape(a1,(6,4))
np.reshape(a1,24)

a2 = np.array([1,2,3,4,5,6,7,8,9,10,11,12])
#randomly shuffles the order of the vector
np.random.shuffle(a2)

#returns the largest element of the vector
np.max(a2)

#returns the index of the largest element of the vector
np.argmax(a2)

#returns the smallest element of the vector
np.min(a2)

#returns the indec of the smallest element of the vector
np.argmin(a2)


"""
simple statistics
"""
#remember to import the stats module
import statistics as stats

data = [91,65,85,66,73]
#mean of the data
stats.mean(data)

#median of the data
stats.median(data)

#mode of the data
stats.mode(data)

#population variance of the data
stats.pvariance(data)

#population standard deviation of the data
stats.pstdev(data)

#import to make graphs
import matplotlib.pyplot as plt

#make a histogram, bins means how many lines
plt.hist(data,bins=50)
#don't forget to show the graph
plt.show()


"""
data visulization
"""
x=[]
s=[]
#makes a grid for the graph
plt.grid(True)

#makes the graph size 1:1 for both horizontal and vertical
plt.axis("equal")

#makes a legend for the graph when there's more than 1 graphs
plt.legend

#plots a line graph, label is used to differentiate the graphs with the legend
plt.plot(x,s,label="sin")


"""
linear regression
"""
#import to get different datasets that could be used for testing
from sklearn import datasets
#import so that you can divide data into training data and testing data
from sklearn.model_selection import train_test_split
#imports linear model
from sklearn import linear_model

#makes a linear regression dataset to guess data, n_features is the number of input variables, noise simulates random errors in real world data
x,y = datasets.make_regression(n_samples=100, n_features=1, noise=30)

#splits the data in the dataset into training data and testing data, test_size means the percentage of the data that'll be used for testing
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.3)

#creates an object for the linear regression model
model = linear_model.LinearRegression()

#trains the model
model.fit(x_train,y_train)

#shows the equation for the data. coef_ is the gradient (length depends on the number of input variables), intercept_ is the y intercept
model.coef_[0] + model.intercept_

#predicts the value of y with the test data
y_pred = model.predict(x_test)

#accuracy of the training model
model.score(x_train, y_train)

#accuracy of the tets model
model.score(x_test, y_test)


"""
decision tree
"""
#import the tree module
from sklearn import tree

#change model to decision tree model
model = tree.DecisionTreeClassifier()

#instead of just appending y, append based on score
y.append("合格")
y.append("不合格")


"""
clustering
"""
#import cluster model
from sklearn import cluster

#makes clusters
data,labels = datasets.make_blobs(n_samples=500,n_features=2,centers=5)

#creates cluster object with K-mean method with 5 centers
model.cluster.KMeans(n_clusters=5)

#label of each cluster
model.labels_

#print each cluster's center's coordinate
model.cluster_centers_

#make a list of elements in only the nth column
data[:,0]

#makes a new color for each different label
c=model.labels_

#creates cluster object with agglomerative clustering method, linkage means distance between clusters, metric means distance between each element
model = cluster.AgglomerativeClustering(n_clusters=5, linkage="ward",metric="euclidean")


"""
dimensionality reduction
"""
#import decomposition
from sklearn import decomposition

iris=datasets.load_iris()
#gets data
x = iris.data

#creates an object that decomposes data into n dimensions
pca = decomposition.PCA(n_components=2)

#loads the data into the object
pca.fit(x)

#transforms data based on pca
x_pca = pca.transform(x)

#target of the iris labels
iris.target
