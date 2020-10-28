#include <stdio.h>
#include <math.h>
#define SWAP(a,b,type)do{\
	type temp;\
	temp = a;\
	a = b;\
	b = temp;\
}while(0)

int N, arr[101], answer[101];

// 최대공약수 구하기
int GCD(int a, int b){
    if(a%b==0) return b;
    return GCD(b,a%b);
}

// 오름차순 정렬
void sort(int* arr,int N){
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(arr[i]>arr[j]) SWAP(arr[i],arr[j],int);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,N);
    int gcd;	// 모든 arr[i]-arr[i+1] 들의 최대공약수
    for(int i=0; i<N-1; i++){
        if(N==2) gcd = arr[1]-arr[0];
        else if(i==0 && N>2) gcd = GCD(arr[1]-arr[0],arr[2]-arr[1]);
        else gcd = GCD(gcd,arr[i+1]-arr[i]);
    }

    int num = 0, temp = 2;
    for(temp=2; temp<sqrt(gcd); temp++){
        if(gcd%temp==0){
            answer[num++]=temp;
            answer[num++]=gcd/temp;
        }
    }

    if(temp*temp==gcd) answer[num++]=temp;
    answer[num]=gcd;

    sort(answer,num+1);
    for(int i=0; i<num+1; i++){
        printf("%d ",answer[i]);
    }
}