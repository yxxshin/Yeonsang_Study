#include <cstdio>
#include <cstring>
using namespace std;

int map[52][52];
int visit[52][52];
int T, M, N, K, cnt = 0;

void dfs(int x, int y){
    // visited map[x][y]
    visit[x][y] = 1;

    // find next node
    if(visit[x+1][y] != 1 && map[x+1][y] == 1 && x+1 < M) {
        dfs(x+1, y);
    }

    if(visit[x][y+1] != 1 && map[x][y+1] == 1 && y+1 < N) {
        dfs(x, y+1);
    }

    if(visit[x-1][y] != 1 && map[x-1][y] == 1 && x-1 >= 0) {
        dfs(x-1, y);
    }

    if(visit[x][y-1] != 1 && map[x][y-1] == 1 && y-1 >= 0) {
        dfs(x, y-1);
    }
    // when no deeper node exist, return (recursion)
}

int main() {

    scanf("%d", &T);
    while (T--) {
        // initialization
        scanf("%d %d %d", &M, &N, &K);
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        while (K--) {
            int input1, input2;
            scanf("%d %d", &input1, &input2);
            map[input1][input2] = 1;
        }

        // dfs
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && visit[i][j] != 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}