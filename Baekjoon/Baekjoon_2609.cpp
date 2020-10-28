#include <stdio.h>
#define MIN(a,b) (((a)>(b))?(b):(a))

int a, b, G, real_a, real_b;
int temp = 2;

void find_G(){
    while(temp<=MIN(real_a,real_b)){
        if(a%temp==0 && b%temp==0){
            G *= temp;
            a /= temp;
            b /= temp;
            continue;
        }
        temp++;
    }
}

int main(){
    scanf("%d %d",&a,&b);
    G = 1;
    real_a = a, real_b = b;
    find_G();
    printf("%d\n",G);
    printf("%d\n",(real_a*real_b)/G);
}