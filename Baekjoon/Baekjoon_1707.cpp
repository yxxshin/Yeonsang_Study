#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_V 20000
#define NOT_VISITED 0
#define WHITE 1
#define BLACK 2

std::vector<int> graph[MAX_V + 1];
// graph[i]: vector of dots connected with dot i

int colors[MAX_V + 2];  // 0: NOT_VISITED, 1: WHITE, 2: BLACK
bool isBip;

void init() {
    isBip = true;
    for(int i = 0; i <= MAX_V; i++) {
        graph[i].clear();
    }
    memset(colors, NOT_VISITED, sizeof(colors));
}

void dfs(int start) {
    for(int i = 0; i < graph[start].size(); i++) {
        int tempDot = graph[start][i];
        if(colors[tempDot] == NOT_VISITED) {
            // if not visited, give an opposite color with mine
            if(colors[start] == WHITE) colors[tempDot] = BLACK;
            else if(colors[start] == BLACK) colors[tempDot] = WHITE;
            dfs(tempDot);
        }
        else if(colors[tempDot] == colors[start]) {
            // if two connected dots have the same color, this graph cannot be a Bipartite Graph
            isBip = false;
            return;
        }
    }
}

int main() {
    int testNum;
    scanf("%d", &testNum);

    while(testNum--) {
        int V, E;
        scanf("%d %d", &V, &E);
        init();

        while(E--) {
            int a, b;
            scanf("%d %d", &a, &b);
            // save the connection a-b to 'graph'
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= V; i++) {
            if(colors[i] == NOT_VISITED) {
                // if dot i is not visited, start dfs
                // Considering a non-connected graph
                colors[i] = WHITE;
                dfs(i);
            }
        }

        if(isBip) printf("YES\n");
        else printf("NO\n");
    }
}