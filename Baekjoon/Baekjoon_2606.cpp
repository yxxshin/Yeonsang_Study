#include <cstdio>
#include <cstring>
using namespace std;

int map[1002][1002];
int visit[1002];
int N, M, count = 0;

void dfs(int V){
    // visited V
    visit[V] = 1;
    count++;

    // find next node
    for(int i = 1; i <= N; i++){
        if(map[V][i] == 1 && visit[i] != 1){
            // when V and i is connected but not visited yet, go to i
            dfs(i);
        }
    }
    // when no deeper node exist, return (recursion)
}

int main() {
    // put inputs
    scanf("%d", &N);
    scanf("%d", &M);

    // initialization
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));

    // connection
    for(int i = 0; i < M; i++){
        int input1, input2;
        scanf("%d %d", &input1, &input2);
        // connect input1 and input2
        map[input1][input2] = 1;
        map[input2][input1] = 1;
    }

    // dfs
    dfs(1);
    printf("%d\n", count-1);
}