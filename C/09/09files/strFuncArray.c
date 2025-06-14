// strFuncArray.c
// 文字列を色々と処理する関数を作る。配列を使った版
// (1)文字列の長さを求める、(2)コピー、(3)連結（追加）、(4)比較

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数（配列版）
int strLength(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 文字列strを文字列newにコピーする関数（配列版）
void strCopy(char new[], char str[]) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        new[i] = str[i];
    }
    new[i] = '\0';    // コピー先に終端文字を追加
}

// 文字列strに文字列addを連結する関数（配列版）
void strAppend(char str[], char add[]) {
    int p = 0, i = 0;

    // str の末尾を探す
    while (str[p] != '\0') {
        p++;
    }

    // add の文字を str にコピー
    while (add[i] != '\0') {
        str[p++] = add[i++];
    }

    // 終端文字を追加
    str[p] = '\0';
}

// 文字列str1と文字列str2を比較する関数（配列版）
// 戻り値は、0:等しい、1:異なる
int strCompare(char str1[], char str2[]) {
    int i = 0;

    // 1文字ずつ比較していく
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 1;  // 違いがある
        }
        i++;    // 次の文字へ
    }

    // どちらかが終了した時点でもう片方にまだ文字が残っていたら違うとする
    if (str1[i] != str2[i]) {
        return 1;  // 違いがある
    }

    return 0;   // 同じ
}

// メイン
int main(void) {
    char str1[MAX_LEN];  // 入力文字列1
    char str2[MAX_LEN];  // 入力文字列2

    // データの入力
    printf("文字列1 ?\n");
    scanf("%s", str1);
    printf("文字列2 ?\n");
    scanf("%s", str2);

    // 処理と結果出力
    printf("文字列1「%s」の長さ: %d\n", str1, strLength(str1));
    printf("文字列2「%s」の長さ: %d\n", str2, strLength(str2));

    printf("2つの文字列の比較結果: ");
    if (strCompare(str1, str2) == 0) {
        printf("同じ\n");
    } else {
        printf("異なる\n");
    }

    strCopy(str2, str1);
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strAppend(str1, str2);
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
