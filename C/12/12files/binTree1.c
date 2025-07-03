// binTree1.c
// 二分木を構造体で作成して、それを深さ優先探索してみる

#include <stdio.h>

// 二分木のノード構造体
typedef struct node {
    int data;           // ノードで記憶するデータ
    struct node *left;  // 左の子へのポインタ
    struct node *right; // 右の子へのポインタ
} Node;

// 関数のプロトタイプ宣言
void dfs(Node *node);

// メイン
int main(int argc, char *argv[]) {
    Node *root;    // ルートノード（根節点）へのポインタ
    Node n1, n2, n3, n4, n5, n6;    // ノード（節点）

    // 各ノードのつながり具合（静的に設定）
    root = &n1;
    n1.data = 1;  n1.left = &n2;   n1.right = &n3;
    n2.data = 2;  n2.left = &n4;   n2.right = &n5;
    n3.data = 3;  n3.left = NULL;  n3.right = &n6;
    n4.data = 4;  n4.left = NULL;  n4.right = NULL;
    n5.data = 5;  n5.left = NULL;  n5.right = NULL;
    n6.data = 6;  n6.left = NULL;  n6.right = NULL;

    // 深さ優先探索で木をなぞる
    dfs(root);    // ルートから再帰呼び出しで処理

    return 0;
}

// 深さ優先探索DFSで巡回（前順 preorderで）
void dfs(Node *node) {
    if (node == NULL) {
        return;
    }

    printf("%d\n", node->data);   // ノードのデータを出力
    dfs(node->left);              // 左部分木を探索
    dfs(node->right);             // 右部分木を探索
}
