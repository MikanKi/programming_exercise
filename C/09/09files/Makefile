# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: ptrArray1 ptrCalc1 funcParam1 strFuncArray strSample charCount1 ptrArray2 ptrCalc2 funcParam2 funcParam3 funcParam4 strFuncPtr charCount2 charCount3 wordLength

# コンパイルによってできるものを削除する
clean:
	rm -f *.o ptrArray1 ptrArray2 ptrCalc1 ptrCalc2 funcParam1 funcParam2 funcParam3 funcParam4 strFuncArray strFuncPtr strSample charCount1 charCount2 charCount3 wordLength
	rm -rf *.dSYM
