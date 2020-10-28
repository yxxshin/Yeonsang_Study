#include <stdio.h>

int N, arr[101];

int GCD(int a, int b){
    if(a%b==0) return b;
    if(b==0) return 1;
    return GCD(b,a%b);
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    int gcd;
    for(int i=1; i<N; i++){
        gcd = GCD(arr[0],arr[i]);
        printf("%d/%d\n",(arr[0]/gcd),(arr[i]/gcd));
    }
}