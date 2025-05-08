/*
  reverse2.c
  5つの整数を入力させ、逆順に表示する。
  配列を単純に使った（繰り返しは使っていない）
*/

//454403　フェリシア・アイヴィー

/* 実行結果

input No.0: 5
input No.1: 4
input No.2: 3
input No.3: 6
input No.4: 78
No.4 = 78
No.3 = 6
No.2 = 3
No.1 = 4
No.0 = 5

*/

#include <stdio.h>

int main(void) {
    int i = 0;
    int array[5];

    while(i<5){
        printf("input No.%d: ",i);
        scanf("%d",&array[i]);
        i++;
    }

    i = 4;

    while(i>=0){
      printf("No.%d = %d\n",i,array[i]);
      i--;
    }

    return 0;
}
