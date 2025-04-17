//calcBMI.c
//2454403 フェリシア・アイヴィー

/* 実行結果

身長をmで、小数点以下2桁まで入力してください。
1.57
体重をkgで、小数点以下1桁まで入力してください。
51.2
身長は1.570000メートルです。
体重は51.200000キログラムです。
BMIは20.771634です。

*/

#include <stdio.h>

int main(void){
    //身長と体重を宣言
    double height, weight;

    //入力
    printf("身長をmで、小数点以下2桁まで入力してください。\n");
    scanf("%lf",&height);
    printf("体重をkgで、小数点以下1桁まで入力してください。\n");
    scanf("%lf",&weight);

    //出力
    printf("身長は%fメートルです。\n",height);
    printf("体重は%fキログラムです。\n",weight);

    //BMI計算
    printf("BMIは%fです。\n",weight/(height*height));

    return 0;
}
