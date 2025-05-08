/*
  reverse1.c
  5つの整数を入力させ、逆順に表示する。
  配列を単純に使った（繰り返しは使っていない）
*/
#include <stdio.h>

int main(void) {
    int i = 0;
    int array[5];

    while(i<5){
      scanf("%d",&array[i]);
      i++;
    }

    i = 4;

    while(i>=0){
      printf("%d\n",array[i]);
      i--;
    }

    return 0;
}
