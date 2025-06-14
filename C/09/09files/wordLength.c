// wordLength.c
// 2454403 フェリシア・アイヴィー

/* 実行結果

The quick brown fox jumps over the lazy dog
最長の単語(5): quick 
最短の単語(3): The 

他はちゃんと動作していない。

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main(void){
    char str[MAX_LEN];
    // char str[MAX_LEN] = "Hello Worlds";
    char *words[MAX_LEN];
    char *strP;
    char **wordP;
    int max = -1, min = 101;
    char *longest, *shortest;
    char maxW[MAX_LEN], minW[MAX_LEN];
    int i,j,k,len;

    strP = str;
    wordP = words;

    printf("単語列?\n");
    fgets(str, MAX_LEN, stdin);

    while(isspace(*strP) == 1){
        strP++;
    }
    *wordP++ = strP;
    len = strlen(str);

    for(k=0;k<len;k++){
        if(isspace(*strP) == 1 || *strP == '\n'){
            if(isspace(*(strP+1)) != 1){
                *wordP = strP+1;
                if (*wordP-*(wordP-1)>max){
                  longest = *(wordP-1);
                    max = *wordP - *(wordP - 1);
                } 
                if (*wordP - *(wordP-1) < min){
                    shortest = *(wordP-1);
                    min = *wordP - *(wordP -1);
                }
                *wordP++;
            }
            
        } 
        strP++;
    }

    for(i=0;i<max;i++){
        if(*longest != '\n'){
            maxW[i] = *longest++;
        }
    }

    for(j=0; j<min; j++){
        if(*shortest != '\n'){
            minW[j] = *shortest++;
        }
    }

    printf("最長の単語(%d): %s\n",max-1,maxW);
    printf("最短の単語(%d): %s\n",min-1,minW);

    
    
    return 0;
}