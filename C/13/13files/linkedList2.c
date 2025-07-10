// linkedList2.c
// 連結リストで単語をアルファベット順に記憶し、出現回数と共に出力する
// 片方向リスト版
// 大文字と小文字を区別しない版
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./linkedList2 <word8.txt
4
2 is
2 my
2 pen
2 this

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100     // 1単語の入力バッファ

// リストの要素を記憶する構造体
typedef struct node {
    char *word;         // 単語データ
    int num;            // 出現回数
    struct node *next;  // 次の要素
} Node;

// リスト構造体
typedef struct {
    Node *head;     // リストの先頭要素へのポインタ
} List;

// 単語が入った要素を作成して、そのアドレス（ポインタ）を返す
Node *createNode(char *word) {
    Node *newNode;

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc failed");
        exit(1);
    }

    newNode->word = strdup(word);   // mallocしてコピー
    if (newNode->word == NULL) {
        perror("strdup failed");
        exit(1);
    }
    newNode->num = 1;               // 出現回数の初期値は1
    newNode->next = NULL;

    return newNode;
}

// リストのソート順で、単語を追加する
void insertNode(List *list, char *word) {
    Node *newNode;  // 新規の要素
    Node *current;  // 現在の位置を覚えるため
    Node *pcurr;    // 1つ手前の位置を覚えるため
    int res;        // strcmp()の結果

    if (list->head == NULL) {  // リストが空の場合は先頭へ
        newNode = createNode(word); // 新規に要素を作成
        list->head = newNode;
        return;
    }

    // 挿入する位置を検索する
    pcurr = NULL;
    current = list->head;
    while (current != NULL && (res = strcmp(word, current->word)) > 0) {
        // strcmp()の結果が正ということは、まだ手前
        pcurr = current;    // 1つ手前の要素を覚えておく
        current = current->next;
    }

    // 単語が一致していたら、登場回数を増やすだけで終了
    if (res == 0) {
        current->num++;
        return;
    }

    // 追加する場所が、末尾、先頭、途中で場合分け
    newNode = createNode(word); // 新規に要素を作成
    if (current == NULL) {  // 末尾に追加

        pcurr->next = newNode;

    } else if (pcurr == NULL) {  // 先頭に追加

        list->head = newNode;
        newNode->next = current;

    } else {    // 中間に追加

        pcurr->next = newNode;
        newNode->next = current;

    }
}

// 単語数を数える
int countNode(List *list) {
    Node *pt;
    pt = list->head;
    int count = 0;
    while(pt != NULL){
        count++;
        pt = pt->next;
    }



    return count;
}

// リスト表示
void outputList(List *list) {
    Node *pt;

    // 単語数を表示
    printf("%d\n", countNode(list));

    // 単語をアルファベット順に表示(出現回数も)
    pt = list->head;
    while (pt != NULL) {
        printf("%d %s\n", pt->num, pt->word);
        pt = pt->next;
    }
}

// メモリ解放
void freeList(List *list) {
    Node *pt;

    pt = list->head;
    while (pt != NULL) {
        Node *nextNode = pt->next;
        free(pt->word);   // 先に単語部分を解放して
        free(pt);         // 次に、要素本体を解放する
        pt = nextNode;
    }

    // リストを空にしておく
    list->head = NULL;
}

// メイン
int main(int argc, char *argv[]) {
    char word[MAX_LENGTH + 1];  // 入力バッファー
    List list = { NULL };       // 連結リストを定義

    // 入力がターミナルならプロンプトを出す
    if (isatty(fileno(stdin))) {
        fprintf(stderr, "スペースや改行で区切った単語を入力 (Ctrl-D で終了):\n"); // 標準エラー出力に送って、標準出力と混ざらないようにする
    }

    // 単語を読み込み、リストに登録
    while (scanf("%100s", word) != EOF) {    // 100文字以下に制限
        for(int i=0; i<strlen(word);i++){
            word[i] = tolower(word[i]);
        }
        insertNode(&list, word);
    }

    // 単語を表示
    outputList(&list);

    // メモリを解放
    freeList(&list);

    return 0;
}
