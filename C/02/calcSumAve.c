//calcSum.c
//2454403 フェリシア・アイヴィー

/*実行結果

123
234
345
456
567
678
789
890
0
合計は4082、平均は510

*/

#include <stdio.h>

int main(void){
    //合計と数値とカウント数を宣言
    int sum = 0,num,count=0;

    //数値が０でない場合、足し算を繰り返し、カウントを１増やす
    do{
        scanf("%d",&num);
        sum = sum + num;
        count++;
    }while(num != 0);

    //出力。countは0を除くので、1引く
    printf("合計は%d、平均は%d\n",sum,sum/(count-1));
    return 0;
}