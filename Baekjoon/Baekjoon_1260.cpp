#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[1002][1002];
int visit[1002];
int N, M, V;
queue<int> q;

void dfs(int V){
    printf("%d ", V);
    // visited V
    visit[V] = 1;

    // find next node
    for(int i = 1; i <= N; i++){
        if(map[V][i] == 1 && visit[i] != 1){
            // when V and i is connected but not visited yet, go to i
            dfs(i);
        }
    }
    // when no deeper node exist, return (recursion)
}

void bfs(int V){
    // use queue
    // visited V
    visit[V] = 1;
    q.push(V);

    // bfs until end of nodes
    while(!q.empty()){
        // visit front node of q
        V = q.front();
        q.pop();
        printf("%d ", V);

        for(int i = 1; i <= N; i++){
            // check other nodes connected with node V
            if(map[V][i] == 1 && visit[i] != 1){
                // if connected and not visited yet, push node in queue and check visited
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}

int main() {
    // put inputs
    scanf("%d %d %d", &N, &M, &V);

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
    dfs(V);
    printf("\n");

    // initialization
    memset(visit, 0, sizeof(visit));

    // bfs
    bfs(V);
    printf("\n");

}