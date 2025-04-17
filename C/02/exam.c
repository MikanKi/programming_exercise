//exam.c
//2454403 フェリシア・アイヴィー

/*実行結果

点数を入力してください：
69
可

*/

#include <stdio.h>

int main(void){
    //点数を宣言
    int score;

    //入力
    printf("点数を入力してください：\n");
    scanf("%d",&score);

    //条件を割り当てる
    if(score >= 90){
        printf("秀\n");
    } else if(score >= 80){
        printf("優\n");
    } else if(score >= 70){
        printf("良\n");
    } else if(score >= 60){
        printf("可\n");
    } else {
        printf("不可\n");
    }
    
    return 0;
}
