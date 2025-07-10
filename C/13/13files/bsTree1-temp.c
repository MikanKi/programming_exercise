// bsTree1.c
// 英単語の二分探索木を構築して、出現頻度と一緒に辞書式順に出力する

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100     // 1単語の入力バッファ

// 二分探索木のノードを表す構造体（単語検索用）
struct node {
    char *word;             // この節点に登録する単語へのポインタ
    int num;                // 単語の出現回数
    struct node *left;      // 左子節点へのポインタ
    struct node *right;     // 右子節点へのポインタ
};

typedef struct node Node; // Nodeという新しい型を定義

// 単語をデータとして持つ節点を作成
Node *newNode(char *word) {
    Node *new;

    new = (Node *)malloc(sizeof(Node));  // 新しい節点の領域を確保
    if (new == NULL) {                   // 確保失敗
        perror("malloc");
        exit(1);
    }

    // 単語を登録する領域を確保






    // 単語を節点のデータ領域へコピー



    // 出現回数は1回目



    // 左右の子節点は無い



    return new;     // 確保した節点へのポインタを返す
}

// 単語を二分探索木に登録
// pt==NULLのときのみ、根節点へのポインタを返す
Node *insertNode(Node *pt, char *word) {
    int cmp;

    if (pt == NULL) {   // 登録単語がゼロなら根節点として新規に作成
        return newNode(word); // 根節点のポインタ（アドレス）を返す
    }

    cmp = strcmp(word, pt->word);   // 登録する単語と登録済み単語を比較
















    return pt;  // 根節点のポインタを返す
}

// 二分探索木の節点数つまり単語数を求める
int countNode(Node *pt) {
    if (pt == NULL)
        return 0;       // ptがNULLなら節点は無いので0を返す



}

// 二分探索木に登録されている単語を辞書式順に出現回数と共に出力
// 木を中順（inorder）でたどればよい
void outputNode(Node *pt) {
    if (pt == NULL)
        return;             // ノードがもうないので何もせず戻る

    outputNode(pt->left);   // 左部分木に再帰的に適用
    printf("%d %s\n", pt->num, pt->word); // この節点に登録されている単語と出現回数を出力
    outputNode(pt->right);  // 右部分木に再帰的に適用
}

// 二分探索木で確保したメモリを全て解放する
// 木を後順（postorder）でたどればよい
void freeNode(Node *pt) {
    if (pt == NULL)
        return;             // ノードがもうないので何もせず戻る

    freeNode(pt->left);     // 左部分木に再帰的に適用
    freeNode(pt->right);    // 右部分木に再帰的に適用
    // 節点のメモリを解放
    free(pt->word);
    free(pt);
}

// メイン
int main(int argc, char *argv[]) {
    Node *root = NULL;  // 根節点へのポインタ。最初は空
    char buff[MAX_LENGTH + 1];

    // 単語を1つずつ読み込み、二分探索木に登録
    while (scanf("%100s", buff) != EOF) {
        root = insertNode(root, buff);
    }

    // 登録単語数を出力
    printf("%d\n", countNode(root));

    // 登録されている単語を出力
    outputNode(root);

    // 確保したメモリを解放する
    freeNode(root);
    root = NULL;

    return 0;
}
