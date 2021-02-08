#include <cstdio>

int main() {
    long long int N;
    scanf("%lld", &N);

    if(N == 1) {
        printf("1\n");
        return 0;
    }
    long long int i = 1;
    long long int temp;
    while(true) {
        temp = 3*i*i - 3*i + 2;
        if(temp > N) break;
        else i++;
    }
    printf("%lld\n", i);
}


