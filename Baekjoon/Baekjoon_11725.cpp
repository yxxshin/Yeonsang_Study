#include <cstdio>
#include <vector>
#define MAX_NODE 100000
using namespace std;

int N;
bool visit[MAX_NODE+2];     // check if visited or not
int parent[MAX_NODE+2];     // parent[i] : parent node of node i
vector<int> tree[MAX_NODE+2];   // save edges

void dfs(int node){
    visit[node] = true;
    for(int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node].at(i);
        // if not visited yet, 'node' is parent of 'next_node'
        if(!visit[next_node]) {
            parent[next_node] = node;
            dfs(next_node);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int input1, input2;
        scanf("%d %d", &input1, &input2);
        // put inputs in tree
        tree[input1].push_back(input2);
        tree[input2].push_back(input1);
    }

    // use dfs to find parent values
    dfs(1);

    // print parent nodes
    for(int i = 2; i <= N; i++){
        printf("%d\n", parent[i]);
    }
}