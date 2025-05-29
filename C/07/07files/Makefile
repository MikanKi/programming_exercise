# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: queen  #loopFuncP2 #loopFuncP1


# maxを生成するためのルール
queen: queen.o module1.o module2.o
	$(CC) $(CFLAGS) -o queen queen.o module1.o module2.o

queen.o: queen.c common.h module1.h module2.h
	$(CC) $(CFLAGS) -c queen.c

module1.o: module1.c common.h module1.h
	$(CC) $(CFLAGS) -c module1.c

module2.o: module2.c common.h module2.h
	$(CC) $(CFLAGS) -c module2.c


# queenを生成するためのルール（課題）