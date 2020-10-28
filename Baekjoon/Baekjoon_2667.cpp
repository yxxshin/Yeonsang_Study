#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[27][27];
int visit[27][27];
int N, cnt = 0;
vector<int> v;

void dfs(int x, int y){
    // visited V
    visit[x][y] = 1;
    cnt++;

    // find next node
    if(visit[x+1][y] != 1 && map[x+1][y] == 1 && x+1 < N) {
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
    // put inputs
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    // initialization
    memset(visit, 0, sizeof(visit));

    // dfs
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && visit[i][j] != 1) {
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    // print answer
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        printf("%d\n", *iter);
    }
}