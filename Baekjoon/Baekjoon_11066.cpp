#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int arr[501];
int sum[501];  // sum[i] = arr[1] + ... + arr[i]
int dp[501][501];   // dp[i][j] : min value for combining arr[i] to arr[j]

int main() {
    // Solution by Dynamic Programming
    // K <= 500, so O(N^3) is okay (500^3 ~ 10^8)
    int T, K;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&K);

        for(int i = 1; i <= K; i++){
            scanf("%d",&arr[i]);
            sum[i] = sum[i-1] + arr[i];
        }

        // dp[i][i] = 0, dp[i][i+1] = 0  ( values added by sum )
        // dp[i][j] = minimum of dp[i][k] + dp[k+1][j] + arr[i] + ... + arr[j]
        //          = minimum of dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]

        // get the value dp[i][i+d]
        for(int d = 1; d < K; d++){
            for(int i = 1; i+d <= K; i++){
                dp[i][i+d] = INT_MAX;
                for(int temp = i; temp < i + d; temp++){
                    dp[i][i+d] = min(dp[i][i+d], dp[i][temp] + dp[temp+1][i+d] + sum[i+d] - sum[i-1]);
                }
            }
        }

        printf("%d\n", dp[1][K]);
    }
}