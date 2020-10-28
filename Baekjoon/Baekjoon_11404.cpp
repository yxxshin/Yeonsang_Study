#include <cstdio>
#include <algorithm>>
#define INF 999999999
using namespace std;

int n, m;
int dp[102][102];  // initial: dp[from][to] = value

void Floyd_Warshall() {
    // consider passing node 'temp'
    for(int temp = 1; temp <= n; temp++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][temp] != INF && dp[temp][j] != INF){
                    dp[i][j] = min(dp[i][j], dp[i][temp] + dp[temp][j]);
                }
            }
        }
    }
}
int main() {
    // put inputs & initalization
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(dp[a][b] > c)
            dp[a][b] = c;
    }

    // Solution by Floyd-Warshall Algorithm
    Floyd_Warshall();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF || i == j) printf("0 ");
            else printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}