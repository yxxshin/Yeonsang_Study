#include <cstdio>
#include <vector>
#define INF 999999999
using namespace std;

typedef struct Road {
    int from;
    int to;
    int value;
};
int N, M;
bool isChanged = false;
vector<Road> map;  // {from,to,value}
long long int dist[502];  // dist[i] : minimum distance to node i, updated

void Relaxation() {
    // relax EVERY ROADS
    for(int i = 0; i < map.size(); i++){
        int from_node = map[i].from;
        int to_node = map[i].to;
        int value = map[i].value;
        // update
        if(dist[from_node] == INF) continue;
        if(dist[to_node] > dist[from_node] + value) {
            dist[to_node] = dist[from_node] + value;
            isChanged = true;
        }
    }
}

void BellmanFord() {
    // Bellman-Ford Algorithm
    dist[1] = 0;    // initialization
    // Relaxation: N-1 times
    for(int i = 1; i <= N-1; i++){
        // relax EVERY ROADS every time
        Relaxation();
    }
    // check if there is negative-cycle
    // if dist changes after N-1 times of Relaxation, it means that there is a negative-cycle
    isChanged = false;
    Relaxation();
    if(isChanged) {
        printf("-1\n");
        return;
    }
    else {
        for(int i = 2; i <= N; i++){
            if(dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
}

int main() {
    // put inputs
    scanf("%d %d", &N, &M);
    while(M--){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        map.push_back( {A,B,C} );
    }

    for(int i = 2; i <= N; i++){
        dist[i] = INF;
    }
    // Solution by Bellman-Ford Algorithm
    BellmanFord();
}