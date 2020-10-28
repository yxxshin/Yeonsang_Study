#include <stdio.h>

long long  N, temp=2;
void factor(int n){
    if(n%temp==0){
        printf("%lld\n",temp);
        N /= temp;
    }
    else temp++;
}

int main() {
    scanf("%lld",&N);
    long long real_N = N;
    while(temp<=real_N) factor(N);
}