// readScore1.c
// 「ID番号 TAB TABを含まない氏名 TAB 点数」という行からなるファイルを
// 引数で指定して、それを連結リストのデータ構造に読み込み、
// 統計情報と点数順でソートした結果を出力する ソートは完成
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./readScore1 score.txt     
項目数: 10 平均: 83.80 標準偏差: 0.00
1006    Sarah Wilson    95
1002    Emily Johnson   91
1008    Olivia Taylor   90
1004    Ashley Davis    88
1010    Megan Thomas    87
1001    James Smith     85
1007    David Moore     81
1003    Michael Brown   78
1005    Chris Miller    74
1009    Joshua Anderson 69

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 読み込むデータを記憶する構造体（リストの要素）
typedef struct node {
    int id;         // ID
    char *name;     // 氏名
    int score;      // 点数
    struct node *next;
} Node;

// 連結リストを構成する構造体
// 最初と最後の要素へのポインタを記憶する
typedef struct list {
    Node *head;
    Node *tail;
} List;

// リストに要素を1つ追加する
void appendNode(List *list, int id, const char *name, int score) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc");
        exit(4);
    }

    // メモリ確保した構造体のメンバの値をセット
    newNode->id = id;

    newNode->name = strdup(name);
    if (newNode->name == NULL){
        perror("strdup failed");
        exit(1);
    }

    newNode->score = score;





    // リストの最後に要素を追加(tailが使える）
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }






}

// リスト全体のメモリを解放する
void freeList(List *list) {
    Node *current = list->head; // 現在位置
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp->name);       // 先に要素の中のデータを解放
        free(temp);             // 次に要素自体を解放
    }
    list->head = list->tail = NULL; // リストを空にしておく
}

// リストをscoreの小さな順にソートする（バブルソートを適用）
// 端から次の要素との大小関係を見て、次が大きいならデータを入れ換える。
// 最後までいって一度も入れ換えが起こらなければソート完了。
// そうでなければ、再びリストの最初から行う。
// 最後のほうに一番小さいデータが移動するので、次はその手前までで止める。
void sortList(List *list) {
    int swapped;    // 入れ換えが発生したかのフラグ
    Node *curr;     // リストの現在位置
    Node *last = NULL;  // 検索する最後の位置（1つずつ前になる）

    if (!list->head)    // リストが空なら何もしない
        return;

    // リストの要素に対してバブルソート
    do {
        // 初期化
        swapped = 0;
        

        // リストを順にたどる
        curr = list->head;
        while (curr->next != last){
            if (curr->score < curr->next->score) {
                // データの入れ換えをする
                int tmp_id;
                int tmp_score;
                char *tmp_name;

                tmp_id = curr->id;
                tmp_score = curr->score;
                tmp_name = curr->name;

                curr->id = curr->next->id;
                curr->score = curr->next->score;
                curr->name = curr->next->name;

                curr->next->id = tmp_id;
                curr->next->score = tmp_score;
                curr->next->name = tmp_name;

                // 入れ換えが発生したフラグをONに
                swapped = 1;
            }
            curr = curr->next;  // 次の要素へ

        }
        last = curr;    // 検索の最後の位置を1つ手前にする
    } while (swapped);  // 一度でも入れ換えをした間は繰り返し
}

// メイン
int main(int argc, char *argv[]) {
    FILE *fp;           // ファイルアクセス用
    List list = {NULL, NULL};   // 一覧を記憶する連結リスト
    char buffer[1000];  // 入力バッファー
    int count = 0;      // 入力の行数
    long sum = 0;       // スコアの合計

    // 引数の数のチェック
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    // 引数1に指定されたファイルを読み出しオープン
    fp = fopen(argv[1], "r");
    if (!fp) {
        perror(argv[1]);
        exit(2);
    }

    // 1行ずつ読み込んで処理
    while (fgets(buffer, sizeof(buffer), fp)) {
        int id, score;
        char name[100];
        // 「整数値 TAB TAB以外の文字列 TAB 整数値」でscanf
        if (sscanf(buffer, "%d\t%[^\t]\t%d", &id, name, &score) == 3) {
            appendNode(&list, id, name, score);
            sum += score;   // 合計値に加算
            count++;        // 行数を1増やす
        }
    }
    // 読み終わったのでクローズしておく
    fclose(fp);

    // 有効な行が1行もないときはエラーにする
    if (count == 0) {
        fprintf(stderr, "有効な行がありません\n");
        exit(3);
    }

    // 平均、標準偏差を計算
    double mean = (double)sum / count;  // 平均
    double variance = 0.0;      // 分散





    double stddev = sqrt(variance / count); // 標準偏差

    // リストをソートする（スコア順に）
    sortList(&list);

    // 画面に出力
    printf("項目数: %d 平均: %.2f 標準偏差: %.2f\n", count, mean, stddev);
    for (Node *node = list.head; node; node = node->next) {
        printf("%d\t%s\t%d\n", node->id, node->name, node->score);
    }

    // 確保したメモリを解放
    freeList(&list);

    return 0;
}
