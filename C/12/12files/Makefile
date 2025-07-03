# マクロ（定数）の定義
CC = hgcc
CFLAGS = -Wall #-g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: structCarPtr1 binTree1 clickDraw1 structCarPtr2 clickDraw2 clickDraw3 #clickDraw4 binTree2

# コンパイルによってできるものを削除する
clean:
	rm -f *.o structCarPtr1 binTree1 clickDraw1  structCarPtr2 binTree2 clickDraw2 clickDraw3 clickDraw4
	rm -rf *.dSYM
