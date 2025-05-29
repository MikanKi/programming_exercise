// myfunc1.c
// 大きな方の数値を返す関数（ファイル分割版）

#include <stdio.h>
#include "myfunc1.h"

// 大きな方の数値を返す
int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
