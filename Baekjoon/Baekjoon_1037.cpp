#include <stdio.h>
#define SWAP(a,b,type) do{\
	type temp;\
	temp = a;\
	a = b;\
	b = temp;\
}while(0)

int N;
long long  arr[50];

void sort(long long* arr){
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(arr[i]>arr[j]) SWAP(arr[i],arr[j],long long);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr);
    if(N%2==0) printf("%lld\n",arr[0]*arr[N-1]);
    else printf("%lld\n",arr[(N-1)/2]*arr[(N-1)/2]);
    return 0;
}