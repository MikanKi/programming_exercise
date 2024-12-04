#454403 フェリシア・アイヴィー

from flask import Flask
import math

app = Flask(__name__)

@app.route("/sqrt/<num>",methods = ["GET"])                             # パスパラメータとして num が与えられる
def sqrt(num):                                                          # num は sqrt() 関数の引数として受け取る
    num = float(num)                                                    # num は float 型で受け取る
    if num < 0:                                                         # num が負の数の場合は，400 のステータスコードを返す
        return "Error: cannot find square root of negative number", 400
    else:                                                               # num の平方根を返します
        return f"{math.sqrt(num)}", 200

app.run(port = 5001, debug = True, host = "0.0.0.0")
