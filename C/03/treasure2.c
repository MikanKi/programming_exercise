//treasure.c
//2454403 フェリシア・アイヴィー

/* 実行結果

宝箱が3つある！どれを開けますか？（1か2か3）4
その番号の箱はありません
宝箱が3つある！どれを開けますか？（1か2か3）1
宝箱は罠だった
敵が現れた

*/

#include <stdio.h> 

int main(void){
    //入力の変数の宣言
    int n=0;

    //1~3以外の番号が入力された場合繰り返し、終了しない
    while (n!=1 && n!=2 && n!=3){
        //入力
        printf("宝箱が3つある！どれを開けますか？（1か2か3）");
        scanf("%d",&n);

        //入力の整数によって、結果が違う
        switch (n){
        case 1:
            printf("宝箱は罠だった\n");
            printf("敵が現れた\n");
            break;
        case 2:
            printf("あなたは宝を手に入れた\n");
            break;
        case 3:
            printf("宝箱は空っぽだった\n");
            break;
        default:
            printf("その番号の箱はありません\n");
            break;
        }
    }
    
    return 0;
}
