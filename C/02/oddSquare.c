#include <stdio.h>

int main(void){
    int count=1;
    do{
        printf("%d\n",count*count);
        count = count+2;
    }while(count<100);
}
