#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_V 10000
using namespace std;

typedef struct Road {
    int start;
    int end;
    int value;
};

bool comp_road(Road r1, Road r2){
    return (r1.value<r2.value);
}

int V, E, ans = 0;
int parent[MAX_V+2];
vector<Road> map;

// Union-Find
int find(int u){
    if(u == parent[u])
        return u;
    else return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) return;
    parent[u] = v;
}

void Kruksal() {
    int count = 0;
    for(int j = 0; j < map.size(); j++){
        // Kruksal Algorithm: pick smallest-value road each time (Greedy Algorithm)
        // make sure the roads don't make a circuit (Union-Find)
        if( find(map[j].start) != find(map[j].end)){
            merge(map[j].start, map[j].end);
            count++;
            ans += map[j].value;
        }
        // There should be V-1 roads at MST
        if(count == V-1)
            break;
    }
}

int main() {
    // inputs
    scanf("%d %d", &V, &E);
    while(E--){
        int A, B, value;
        scanf("%d %d %d", &A, &B, &value);
        map.push_back({A,B,value});
    }

    // initialization
    for(int i = 1; i <= V; i++){
        parent[i] = i;
    }

    // sort roads by "value" for Kruksal Algorithm
    sort(map.begin(), map.end(), comp_road);

    // Kruksal Algorithm
    Kruksal();

    // print answer
    printf("%d\n", ans);
}