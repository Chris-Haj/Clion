#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    for(int i=0;i<18;i++){
        printf("%d\n",rand()%10);
    }
    return 0;
}