#include <cstdio>
#include <algorithm>
using namespace std;

int N, C;

int main() {
    // get inputs
    scanf("%d %d", &N, &C);
    long long int* arr = new long long int[N];
    for(int i = 0; i < N; i++){
        scanf("%lld",&arr[i]);
    }

    // sort input array
    sort(arr, arr+N);

    // Binaray Search
    long long int left, right, middle, answer = 0;
    int temp, next, count;
    left = 1, right = arr[N-1] - arr[0];

    while(left <= right) {
        middle = (left + right) / 2;
        temp = 0, next = 1, count = 1;

        // check if this case is possible
        while(next < N){
            if(arr[next] - arr[temp] < middle) {
                // shouldn't place
                next++;
            }

            else if(arr[next] - arr[temp] >= middle) {
                // place
                temp = next;
                next++;
                count++;
            }
        }

        if(count >= C) {
            // okay, but should check more
            answer = middle;
            left = middle + 1;
        }

        else if(count < C){
            // need to place more
            right = middle - 1;
        }
    }

    printf("%lld\n", answer);
    delete[] arr;
}