//treasure.c
//2454403 フェリシア・アイヴィー

/* 実行結果

宝箱が3つある！どれを開けますか？（1か2か3）1
宝箱は罠だった
敵が現れた

宝箱が3つある！どれを開けますか？（1か2か3）2
あなたは宝を手に入れた

宝箱が3つある！どれを開けますか？（1か2か3）3
宝箱は空っぽだった

宝箱が3つある！どれを開けますか？（1か2か3）4
その番号の箱はありません

*/

#include <stdio.h> 

int main(void){
    int n;

    printf("宝箱が3つある！どれを開けますか？（1か2か3）");
    scanf("%d",&n);

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

    return 0;
}
