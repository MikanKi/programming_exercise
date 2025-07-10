# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall #-g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: dispTime1 dirList1 shuffleLine dispTime2 dirList2 linkedList1 bsTree1 linkedList2 #dirList3 findFile 

# コンパイルによってできるものを削除する
clean:
	rm -f *.o dispTime1 dirList1 shuffleLine dispTime2 dirList2 dirList3 findFile linkedList1 linkedList2 bsTree1
	rm -rf *.dSYM
