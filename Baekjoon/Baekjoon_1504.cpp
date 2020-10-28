#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 999999999

int N, E, v1, v2;
int dist[802];     // dist[i] : minimum distance going to node i, gets updated
int map[802][802];  // map[i][j] = map[j][i] : distance from node i to j, if no road 0

int Dijkstra(int from, int to) {
    // Dijkstra Algorithm using priority_queue
    // initialization
    for(int i = 1; i <= N; i++)
        dist[i] = INF;

    // definition
    priority_queue< pair<int,int> > pq;
    pq.push( make_pair(0,from) );
    dist[from] = 0;

    while(!pq.empty()) {
        int current_node = pq.top().second;
        int cost = (-1) * pq.top().first;   // to use priority_queue as minimum heap
        pq.pop();

        // update values of dist
        for(int i = 1; i <= N; i++){
            // test every node connected with 'current_node'
            if(map[current_node][i] == 0) continue;

            int new_cost = cost + map[current_node][i];
            int before_cost = dist[i];

            // if new_cost < before_cost, update
            if(new_cost < before_cost) {
                dist[i] = new_cost;
                pq.push( make_pair(-1 * new_cost, i) );
            }
        }
    }

    if(dist[to] == INF) return -1;
    else return dist[to];
}

int main() {
    // put inputs & initialization
    scanf("%d %d", &N, &E);
    while(E--){
        int from, to, value ;
        scanf("%d %d %d", &from, &to, &value);
        map[from][to] = value;
        map[to][from] = value;
    }
    scanf("%d %d", &v1, &v2);

    // solution by Dijkstra Algorithm
    int d1 = INF, d2 = INF;
    if(Dijkstra(1,v1) != -1 && Dijkstra(v1,v2) != -1 && Dijkstra(v2,N) != -1)
        d1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
    if(Dijkstra(1,v2) != -1 && Dijkstra(v2,v1) != -1 && Dijkstra(v1,N) != -1)
        d2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);

    if(d1 == INF && d2 == INF)
        printf("-1\n");
    else
        printf("%d\n", min(d1, d2));
}