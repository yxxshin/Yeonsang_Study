#include <cstdio>
#define MAX_N 200
#define MAX_M 1000
using namespace std;

int N, M;
bool ans = true;
int parent[MAX_N+3];    // parent[i] : i'th node's parent
int level[MAX_N+3];     // level[i]: tree level which i'th node is included
int plan[MAX_M+3];
int find(int u) {
    // if root node, return
    if(u == parent[u])
        return u;

        // else : go up to find root node
    else {
        // path compression : every parent[node] would be root, so time is saved for second time
        return parent[u] = find(parent[u]);
    }
}

// Union : merge tree u to tree v
void merge(int u, int v){
    // find u and v 's root node
    u = find(u);
    v = find(v);

    // if roots are same, they are already in the same tree
    if(u == v)
        return;

    // if tree 'u' is deeper than 'v', swap
    if(level[u] > level[v]){
        int temp = u;
        u = v;
        v = temp;
    }

    // merge two trees
    parent[u] = v;

    // if the two trees have same level, +1
    if(level[u] == level[v])
        level[v]++;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    // initialization
    for(int i = 1; i <= N; i++){
        parent[i] = i;  // root node : parent is itself
        level[i] = 1;
    }

    // Merge by inputs
    int input;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &input);
            if(input == 1){
                merge(i,j);
            }
        }
    }

    // get plan
    for(int i = 0; i < M; i++) {
        scanf("%d", &plan[i]);
    }

    // find if we can travel by plan
    for(int i = 0; i < M-1; i++){
        if( find(plan[i]) != find(plan[i+1]) ) {
            ans = false;
            break;
        }
    }

    // print answer
    if(ans) printf("YES\n");
    else printf("NO\n");
}