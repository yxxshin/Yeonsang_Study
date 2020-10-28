#include <stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))

// nCk 를 arr[n][k] 에 담자
int arr[1001][1001];

int main(){
    int N, K;
    scanf("%d %d",&N,&K);
    for(int i=1; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(j==0 || i==j){
                arr[i][j]=1;
                continue;
            }
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%10007;
            // nCk + nC(k+1) = (n+1)C(k+1) 임을 이용
        }
    }

    printf("%d",arr[N][K]);
}