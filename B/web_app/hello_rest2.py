# hello_rest2.py
from flask import Flask, request

app = Flask(__name__)

@app.route("/", methods = ["GET"])  # GET メソッドで / にアクセスされたときに
def hello():                        # hello() 関数を実行する．
    name = request.args.get("name") # リクエストパラメータ name を取得する．
    if name:
        return f"Hello, {name} and REST World!", 200
    return "Hello, REST World!", 200

@app.route("/<name>", methods = ["GET"]) # パスパラメータとして name が与えられる．
def hello_name(name):                    # name は hello_name() 関数の引数として受け取る．
    return f"Hello, {name}!", 200

@app.route("/hello", methods = ["POST"]) # POST メソッドで /hello にアクセスされたときに 
def hello_post():                        # hello_post() 関数を実行する．
    name = request.form.get("name")      # リクエストボディの name を取得する．
    if name:
        return f"Hello, {name} and REST POST World!", 200
    return "Hello, REST POST World!", 200

# ポート番号 5001 で Web アプリケーションを実行する．
app.run(port = 5001, debug = True, host = "0.0.0.0") 
# host = "0.0.0.0" の指定を忘れると，localhost からのアクセスしか受け付けなくなります．
# どこからでもアクセスできるようにするためには，host = "0.0.0.0" の指定が必要となります．
