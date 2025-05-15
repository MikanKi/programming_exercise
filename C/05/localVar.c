// localVar.c
// 関数内やグローバル変数で同じ変数名が使われる場合の例
// 2454403 フェリシア・アイヴィー

/* 実行結果

main: 10
func1: 1
func1: 11
func2: 10
func2: 2
func3: 0
func3: 3
main: 10

*/

#include <stdio.h>

int a = 0;  // グローバル変数

void func1(void) {
    int a;  // 関数内のローカル変数

    a = 1;  // 関数内のローカル変数が優先される
    printf("func1: %d\n", a);

    if (1) {
        int a = 11;  // このローカル変数aはこのブロック内だけで有効
        printf("func1: %d\n", a);
    }
}

void func2(int a) { // 引数（仮引数）の変数aは、この関数のローカル変数とみなされる
    printf("func2: %d\n", a);
    a = 2;  // 関数内のローカル変数（仮引数）が使用される
    printf("func2: %d\n", a);
}

void func3(void) {
    printf("func3: %d\n", a);
    a = 3;  // 関数内にないので、グローバル変数が使用される
    printf("func3: %d\n", a);
}

int main(void) {
    int a = 10;  // main関数内の変数a

    printf("main: %d\n", a);
    func1();     // func1は、関数内のローカル変数aを対象としている
    func2(a);    // func2は、仮引数のローカル変数aを対象としている
    func3();     // func3は、グローバル変数aを対象としている
    printf("main: %d\n", a);
    // なお、同じ名前のローカル変数があると、グローバル変数にはアクセスできない
    return 0;
}
