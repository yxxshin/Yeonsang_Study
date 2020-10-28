#include <stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))

int N, K;
int main(){
    scanf("%d %d",&N,&K);
    K = MIN(K,N-K);

    int up=1, down=1;	//분자, 분모
    for(int i=1; i<=K; i++){
        up *= N--;
        down *= i;
    }
    printf("%d",up/down);

}