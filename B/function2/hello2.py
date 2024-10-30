#454403 フェリシアアイヴィー

# ここに hello 関数を定義してください．
def hello(a = "default"):       #デフォルト値を設定する
    if a == "default":          #引数に何も与えられない場合
        return "Hello World"
    elif a == "Python":         #引数に"Python"が与えられた場合
        return "Hi! Python"
    elif type(a) == str:        #引数に文字列が与えられた場合
        return "Hello "+a

# 以下のテストコードは変更しないでください．
assert hello() == "Hello World",          "Error: hello() が 'Hello World' を返しません．"
assert hello("Python") == "Hi! Python",   "Error: hello('Python') が 'Hi Python' を返しません．"
assert hello("Tamada") == "Hello Tamada", "Error: hello('Tamada') が 'Hello Tamada' を返しません．"
