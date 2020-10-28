#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

void Binaray_Search(int* arr, int target) {
    // arr should be sorted
    int left = 0, right = N - 1;
    while(left <= right) {
        int middle = (left + right) / 2;
        if(arr[middle] > target) {
            right = middle - 1;
            continue;
        }
        else if(arr[middle] < target) {
            left = middle + 1;
            continue;
        }
        else if(arr[middle] == target) {
            printf("1\n");
            return;
        }
    }
    // target doesn't exist in arr
    printf("0\n");
}

int main() {
    // get inputs
    scanf("%d",&N);
    int* arr = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&M);
    int* brr = new int[M];
    for(int i = 0; i < M; i++){
        scanf("%d",&brr[i]);
    }

    // sort array
    sort(arr, arr+N);

    // Binaray Search
    for(int i = 0; i < M; i++){
        Binaray_Search(arr, brr[i]);
    }

    delete[] arr;
    delete[] brr;
}