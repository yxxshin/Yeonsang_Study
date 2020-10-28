#include <cstdio>
#include <algorithm>
#define INF 999999999
using namespace std;
int V, E;
int dp[402][402];

void Floyd_Warshall() {
    // consider passing node 'temp'
    for(int temp = 1; temp <= V; temp++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(dp[i][temp] != INF && dp[temp][j] != INF){
                    dp[i][j] = min(dp[i][j], dp[i][temp] + dp[temp][j]);
                }
            }
        }
    }
}
int main() {
    // get inputs & initialization
    scanf("%d %d", &V, &E);
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    while(E--){
        int from, to, value;
        scanf("%d %d %d", &from, &to, &value);
        if(dp[from][to] > value)
            dp[from][to] = value;
    }

    Floyd_Warshall();

    int ans = INF;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j) ans = min(ans, dp[i][j] + dp[j][i]);
        }
    }

    if(ans == INF)
        printf("-1\n");
    else printf("%d\n", ans);
}