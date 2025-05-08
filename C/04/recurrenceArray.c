//recurrenceArray.c
//2454403 フェリシア・アイヴィー

/* 実行結果

9565937
3188645
1062881
354293
118097
39365
13121
4373
1457
485
161
53
17
5
1

*/

#include <stdio.h>
#define SIZE 15

int main(void){
    //arrayとインデックスを宣言。array[0]だけ初期化する
    int array[SIZE] = {1};
    int i,j;

    //次の値を代入する
    for(i=0;i<SIZE-1;i++){
        array[i+1]= 3*array[i] + 2;
    }

    //逆順に表示する
    for(j=SIZE-1;j>=0;j--){
        printf("%d\n",array[j]);
    }
    
    return 0;
}
