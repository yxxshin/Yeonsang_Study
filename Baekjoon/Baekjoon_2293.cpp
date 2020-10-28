#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    int* coins = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&coins[i]);
    }

    // Solution by Dynamic Programming
    int dp[10001] = {0,};
    dp[0] = 1;  // initialization

    // overwrite array dp while increasing coin types
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++) {
            if(coins[i] <= j)   // use dp[0]=1
                dp[j] += dp[j-coins[i]];
        }
    }


    printf("%d\n", dp[k]);
    delete[] coins;
}