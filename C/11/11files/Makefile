# マクロ（定数）の定義
CC = hgcc
CFLAGS = -Wall -g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: structCar1 fishStruct1 structCar2 structCar3 structCarEnum fishStruct2 fishStruct3 fishStruct4 fishStruct3Kai #fishStruct4Kai

# コンパイルによってできるものを削除する
clean:
	rm -f *.o structCar1 fishStruct1 structCar2 structCar3 structCarEnum fishStruct2 fishStruct3 fishStruct4 fishStruct3Kai fishStruct4Kai
	rm -rf *.dSYM
