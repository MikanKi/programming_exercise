import os

#directory list
#returns list
dirs = os.listdir("root")

#if path is directory
if os.path.isdir(dirs[0]):
    pass

#if path is file
if os.path.isfile(dirs[0]):
    pass

#joins 2 paths together with a /
path = os.path.join("root", dirs[0])





#defines a class
class Person:
    pass

#self as initial parameter, an instance
#called a method
def get_name(self):
    pass

    #the object self's variable name
    #instance variable
    self.name

#p is an object in class Person
p = Person()

#calls the method get_name for instance p
p.get_name()

#accepts initial values for variables
#constructor
def __init__(self,name,age):
    
    #takes in value of name into the instance's variable
    self.name = name





#if there's a file called person.py with class Person in it
#imports classes from person.py
import person

#imports from person.py under a different name
import person as p

#imports only one class, Person from person.py
from person import Person

#imports from user/person.py
import user.person





#GET: get resource
#POST: create resource
#PUT: update resource
#DELETE: delete resource

#1xx: information
#100: received request
#2xx: success
#200: request succeeded
#201: resource created
#3xx: moved permanently
#4xx: client error
#400: bad request
#404: not found
#5xx: server error
#500: internal server error

#send a get request to the website
#-i: include response header
curl -i http://example.com

#-v: include request header
curl -v https://google.co.jp

#import flask and request
from flask import Flask , request

#creates flask app
app = Flask(__name__)

#access point, method get
@app.route("/", methods = ["GET"])

#has to have a function right below
def hello():
    #retrieves value for name after ?
    name = request.args.get("name")
    #status code at the end
    return "Hello, REST World!",200

#takes in a parameter name from access point
@app.route("/<name>", methods = ["GET"])
def hello_name(name):
    pass

#access by post
@app.route("/hello",methods = ["POST"])
def hello_post():
    #retrieves value for name from request body
    name = request.form.get("name")

#runs the app at the port number 
app.run(port = 5001, debug = True, host = "0.0.0.0")

#accesses /, retrieves value for variable name
#has to be string
curl "http://localhost:5001/?name=John"

#-X sets the HTTP method
#-d sets the request body
#sets value of name in request body
curl http://localhost:5001/hello -X POST -d "name=Jane"

