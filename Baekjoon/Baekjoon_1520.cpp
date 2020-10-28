#include <cstdio>
using namespace std;

int M, N;
int map[502][502] = {0,};
int dp[502][502] = {0,};    // number of cases from map[i][j] to end

int func(int i, int j){
    // starts from map[i][j]
    // Dynamic Programming: if already value exists, use it
    if(dp[i][j] != -1){  // dp[i][j] = -1 : not visited
        return dp[i][j];
    }
    else {
        dp[i][j] = 0;

        if(map[i+1][j] < map[i][j] && i+1 <= M) {
            // move to map[i+1][j]
            dp[i][j] += func(i+1, j);
        }

        if(map[i-1][j] < map[i][j] && i-1 >= 1){
            // move to map[i-1][j]
            dp[i][j] += func(i-1, j);
        }

        if(map[i][j+1] < map[i][j] && j+1 <= N){
            // move to map[i][j+1]
            dp[i][j] += func(i, j+1);
        }

        if(map[i][j-1] < map[i][j] && j-1 >= 0){
            // move to map[i][j-1]
            dp[i][j] += func(i, j-1);
        }
    }

    return dp[i][j];
}


int main() {
    scanf("%d %d", &M, &N);

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    // start from map[1][1]
    // find every cases
    dp[M][N] = 1;
    int answer = func(1,1);
    printf("%d\n", answer);
}