#454403 フェリシアアイヴィー

# ここに hello 関数を定義してください．
def hello(*a):                  #可変長引数で引数の数を確認し、
    if len(a) == 0:             #引数に何も与えられない場合
        return "Hello World"
    elif a[0] == "World":          #引数に"Python"が与えられた場合
        return "Hi! World"
    elif type(a[0]) == str:        #引数に文字列が与えられた場合
        return "Hello "+a[0]

# 以下のテストコードは変更しないでください．
assert hello() == "Hello World",          "Error: hello() が 'Hello World' を返しません．"
assert hello("Python") == "Hello Python", "Error: hello('Python') が 'Hello Python' を返しません．"
assert hello("World") == "Hi! World",     "Error: hello('World') が 'Hi! World' を返しません．"
