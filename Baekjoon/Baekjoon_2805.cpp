#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    // get inputs
    scanf("%d %d", &N, &M);
    long long int* arr = new long long int[N];
    for(int i = 0; i < N; i++){
        scanf("%lld",&arr[i]);
    }

    // sort input array
    sort(arr, arr+N);

    // Binaray Search
    long long int left, right, middle, answer = 0;
    left = 1, right = arr[N-1];

    while(left <= right) {
        long long int length = 0;
        middle = (left + right) / 2;
        for(int i = 0; i < N; i++){
            if(arr[i] > middle) length += (arr[i] - middle);
        }

        if(length < M) right = middle - 1;
        else if(length >= M) {
            if(middle > answer) answer = middle;
            left = middle + 1;
        }
    }

    printf("%lld\n", answer);
    delete[] arr;
}