#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 999999999

int V, E, K;
int dist[20002];     // dist[i] : minimum distance going to node i, gets updated
vector< pair<int,int> > map[20002];     // connected node information : {to,value}

void Dijkstra() {
    // Dijkstra Algorithm using priority_queue
    priority_queue< pair<int,int> > pq;
    pq.push( make_pair(0,K) );
    dist[K] = 0;

    while(!pq.empty()) {
        int current_node = pq.top().second;
        int cost = (-1) * pq.top().first;   // to use priority_queue as minimum heap
        pq.pop();

        // update values of dist
        for(int i = 0; i < map[current_node].size(); i++){
            int test_node = map[current_node][i].first;
            int new_cost = cost + map[current_node][i].second;
            int before_cost = dist[test_node];

            // if new_cost < before_cost, update
            if(new_cost < before_cost) {
                dist[test_node] = new_cost;
                pq.push( make_pair(-1 * new_cost,test_node) );
            }
        }
    }
}

int main() {
    // put inputs & initialization
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    while(E--){
        int from, to, value ;
        scanf("%d %d %d", &from, &to, &value);
        map[from].push_back(make_pair(to,value));
    }
    for(int i = 1; i <= V; i++)
        dist[i] = INF;

    // solution by Dijkstra Algorithm
    Dijkstra();

    // print
    for(int i = 1; i <= V; i++){
        if(dist[i] != INF) printf("%d\n", dist[i]);
        else printf("INF\n");
    }

}