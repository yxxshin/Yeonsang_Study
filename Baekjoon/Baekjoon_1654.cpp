#include <cstdio>
#include <algorithm>
using namespace std;

int K, N;

int main() {
    // get inputs
    scanf("%d %d", &K, &N);
    long long int* arr = new long long int[K];
    for(int i = 0; i < K; i++){
        scanf("%lld",&arr[i]);
    }

    // sort input array
    sort(arr, arr+K);

    // Binaray Search
    long long int left, right, middle, answer = 0;
    left = 1, right = arr[K-1];

    while(left <= right) {
        long long int count = 0;
        middle = (left + right) / 2;
        for(int i = 0; i < K; i++){
            count += (arr[i]/middle);
        }

        if(count < N) right = middle - 1;
        else if(count >= N) {
            if(middle > answer) answer = middle;
            left = middle + 1;
        }
    }

    printf("%lld\n", answer);
    delete[] arr;
}