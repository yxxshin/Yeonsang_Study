#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int Upper_Bound(int* arr, int target) {
    int upper_bound = -1;
    int left = 0, right = N-1;
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
            upper_bound = middle;
            left = middle + 1;
            continue;
        }
    }
    return upper_bound;
}

int Lower_Bound(int* arr, int target) {
    int lower_bound = -1;
    int left = 0, right = N-1;
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
            lower_bound = middle;
            right = middle - 1;
            continue;
        }
    }
    return lower_bound;
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
        int upper = Upper_Bound(arr, brr[i]);
        int lower = Lower_Bound(arr, brr[i]);
        if(upper == -1) printf("0 ");   // brr[i] doesn't exist in arr
        else printf("%d ", upper - lower + 1);
    }

    delete[] arr;
    delete[] brr;
}