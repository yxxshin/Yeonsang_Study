#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

#define MAX_N 100000
#include <algorithm>
int main()
{
    int n, x, arr[MAX_N+2];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    // Solution by Two-Pointer
    sort(arr, arr + n);

    int start = 0, end = n-1, sum = 0, count = 0;
    while(start != end) {
        sum = arr[start] + arr[end];
        if(sum > x) {
            end--;
        } else if(sum < x) {
            start++;
        } else {
            count++;
            start++;
        }
    }
    printf("%d\n", count);
}