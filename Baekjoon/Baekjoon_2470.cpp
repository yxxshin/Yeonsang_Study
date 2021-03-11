#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

#include <algorithm>
#include <cstdlib>
#define MAX_N 100000
#define INF 0xffffffff
using ll = long long;

int main()
{
    int N;
    scanf("%d", &N);
    ll arr[MAX_N+2];
    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    // Solution by Two-Pointer
    sort(arr, arr+N);

    int s = 0, e = N-1;
    ll sum = 0, minVal = INF, optS = 0, optE = 0;

    while(s != e) {
        sum = arr[s] + arr[e];
        dbg(s, e, sum);
        if(llabs(sum) < minVal) {
            optS = arr[s];
            optE = arr[e];
            minVal = llabs(sum);
        }

        if(sum > 0) {
            e--;
        } else {
            s++;
        }
    }

    printf("%lld %lld", optS, optE);
}