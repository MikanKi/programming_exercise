# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: copyFile1 fileStat copyFile2 copyFile4 copyFile5 readScore1 readScore2 filePerm #copyFile6 #copyFile3 revCat

# コンパイルによってできるものを削除する
clean:
	rm -f *.o copyFile1 fileStat   copyFile2 copyFile3 copyFile4 copyFile5 revCat readScore1 readScore2 filePerm copyFile6 
	rm -rf *.dSYM
