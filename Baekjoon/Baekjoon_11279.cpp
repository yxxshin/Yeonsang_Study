#include <cstdio>
#include <algorithm>
#define SWAP(a,b,type) do{ \
    type temp; \
    temp=a; \
    a=b; \
    b=temp; \
}while(0)

using namespace std;

// make heap
long long int arr[100002] = {0,};
int size = 0;

// input number
void push_heap(long long int x){
    // put number in the back
    size++;
    arr[size] = x;

    // sort the heap
    int child = size, parent = child/2;
    while(parent >= 1) {
        if(arr[child] > arr[parent]){
            SWAP(arr[child], arr[parent], long long int);
            child /= 2;
            parent = child/2;
        }
        else break;
    }
}

// pop max number
void pop_heap(){
    if(size == 0) {
        printf("0\n");
        return;
    }

    long long int max_num = arr[1];
    arr[1] = arr[size];
    arr[size] = 0;
    size--;                 // copy the last value to the top, and delete

    // sort heap
    int parent = 1;
    while(parent * 2 <= size) {
        // compare the parent node with two childs
        if(arr[parent] < max(arr[parent*2], arr[parent*2 +1]) ) {
            // swap with the bigger child
            if(arr[parent*2] > arr[parent*2+1]) {
                SWAP(arr[parent], arr[parent*2], long long int);
                parent = parent * 2;
            }
            else {
                SWAP(arr[parent], arr[parent*2+1], long long int);
                parent = parent * 2 + 1;
            }
        }
        else break;
    }
    // print max number
    printf("%lld\n",max_num);
}


int main() {
    int N;
    scanf("%d",&N);
    long long int brr[N];
    for(int i = 0; i < N; i++){
        scanf("%lld",&brr[i]);
        if(brr[i]==0) pop_heap();
        else push_heap(brr[i]);
    }
}