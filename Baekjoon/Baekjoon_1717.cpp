#include <cstdio>
#define MAX_N 1000000
using namespace std;

int n, m;
int parent[MAX_N+3];    // parent[i] : i'th node's parent
int level[MAX_N+3];     // level[i]: tree level which i'th node is included
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
    scanf("%d %d", &n, &m);
    // initialization
    for(int i = 1; i <= n; i++){
        parent[i] = i;  // root node : parent is itself
        level[i] = 1;
    }

    while(m--){
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        if(type == 0)
            merge(a,b);

        else if(type == 1){
            if( find(a) == find(b) ){
                // in the same tree
                printf("YES\n");
            }
            else{
                // in different tree
                printf("NO\n");
            }
        }

    }
}