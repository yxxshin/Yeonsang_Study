#include <cstdio>
#define MAX_G 100000
using namespace std;

int G, P, main_root, ans;
int parent[MAX_G+3];    // parent[i] : i'th node's parent
int input[MAX_G+3];
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

    // merge two trees
    parent[u] = v;
}

int main() {
    scanf("%d", &G);
    scanf("%d", &P);
    // initialization
    for(int i = 0; i <= G; i++){
        parent[i] = i;  // root node : parent is itself
    }

    // put inputs
    for(int i = 1; i <= P; i++){
        scanf("%d", &input[i]);
    }

    // solve question
    for(ans = 1; ans <= P; ans++){
        int temp = find(input[ans]);
        // if the result of "find(input)" is 0, it means that there is no space left
        if(temp != 0){
            // union the gate and the gate before
            merge(temp, temp-1);
            continue;
        }
        else break;
    }
    printf("%d\n", ans-1);
}