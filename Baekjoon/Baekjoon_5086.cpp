#include <stdio.h>

void checker(int a, int b){
    if(a%b==0) printf("multiple\n");
    else if(b%a==0) printf("factor\n");
    else printf("neither\n");
}

int a, b;

int main() {

    scanf("%d %d",&a,&b);
    while(a!=0 && b!=0) {
        checker(a,b);
        scanf("%d %d",&a,&b);
    }

    return 0;
}