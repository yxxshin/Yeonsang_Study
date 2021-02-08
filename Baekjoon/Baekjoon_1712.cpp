#include <cstdio>

int main() {
    long long int A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    if(B >= C) printf("-1\n");
    else printf("%lld\n", (long long int)A/(C-B) + 1);
}