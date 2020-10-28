#include <cstdio>
#include <vector>
#include <cstring>
#define MAX_NODE 100000
using namespace std;

// Idea : pick the farthest node from any node
// Then, find the farthest node from 'that' node

int V, farthest_node, max_value;
bool visit[MAX_NODE+2];     // check if visited or not
vector< pair<int,int> > tree[MAX_NODE+2];   // tree[start].{end,value}

void dfs(int node, int dist){
    // if already visited, return
    if(visit[node])
        return;

    // update
    visit[node] = true;
    if(max_value < dist) {
        max_value = dist;
        farthest_node = node;
    }

    // dfs
    for(int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node].at(i).first;
        int next_value = dist + tree[node].at(i).second;
        // if not visited yet, 'node' is parent of 'next_node'
        if(!visit[next_node]) {
            dfs(next_node, next_value);
        }
    }
}

int main() {
    // save inputs
    scanf("%d", &V);
    for(int i = 0; i < V; i++){
        int start, end, value;
        scanf("%d", &start);
        scanf("%d", &end);
        while(end != -1){
            scanf("%d", &value);
            tree[start].push_back(make_pair(end, value));
            scanf("%d", &end);
        }
    }

    // find the farthest node from any node. (This case, from node 1)
    memset(visit, false, sizeof(visit));
    dfs(1,0);

    // find the max_distance from 'farthest_node'
    memset(visit, false, sizeof(visit));
    dfs(farthest_node, 0);

    // print
    printf("%d\n", max_value);
}