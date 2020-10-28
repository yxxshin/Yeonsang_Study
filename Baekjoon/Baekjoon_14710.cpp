#include <cstdio>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int a1 = a % 30;
    if(b == a1 * 12)
        printf("O\n");
    else printf("X\n");
}