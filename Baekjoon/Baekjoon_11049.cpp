#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

struct Array {
    int r, c;
} ;

int main() {
    int N;
    scanf("%d",&N);
    Array* arr = new Array[N+2];
    for(int i = 1; i <= N; i++){
        scanf("%d",&arr[i].r);
        scanf("%d",&arr[i].c);
    }

    // Dynamic Programming
    int dp[502][502] = {0,};    // dp[i][j] = minimum value of arr[i] * ... * arr[j]

    for(int d = 1; d < N; d++) {
        for(int i = 1; i+d <= N; i++){
            dp[i][i+d] = INT_MAX;
            for(int temp = i; temp < i+d; temp++){
                dp[i][i+d] = min(dp[i][i+d], dp[i][temp] + dp[temp+1][i+d] + arr[i].r * arr[temp].c * arr[i+d].c);
            }
        }
    }

    printf("%d\n", dp[1][N]);

    delete[] arr;
}