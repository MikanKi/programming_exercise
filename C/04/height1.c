#include <stdio.h>

int main(void){
    int height[] = {163,157,176,180,166};
    int i;

    printf("番号?");
    scanf("%d",&i);
    printf("%d番の身長は%dcmです。",i,height[i]);
    
    return 0;
}
