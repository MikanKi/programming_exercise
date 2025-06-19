# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall #-g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: strArray strInputAlloc1 argDump argSearch1 funcSignal funcBranch1 funcBranch2 funcArray1 strInput strInputAlloc2 argSearch2 funcArray2 funcArray3

# コンパイルによってできるものを削除する
clean:
	rm -f *.o strArray strInputAlloc1 argDump argSearch1 funcSignal funcBranch1 funcBranch2 funcArray1 strInput strInputAlloc2 argSearch2 argSearchRE funcArray2 funcArray3
	rm -rf *.dSYM
