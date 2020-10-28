#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 999999999

int dist[50002];     // dist[i] : minimum distance going to node i, gets updated
vector< pair<int,int> > map[50002];  // map[from].{to,value} , if no road 0
int n;

int Dijkstra(int from, int to) {
    // Dijkstra Algorithm using priority_queue
    // initialization
    for(int i = 1; i <= n; i++)
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
        for(int i = 0; i < map[current_node].size(); i++){
            int test_node = map[current_node][i].first;
            int new_cost = cost + map[current_node][i].second;
            int before_cost = dist[test_node];

            // if new_cost < before_cost, update
            if(new_cost < before_cost) {
                dist[test_node] = new_cost;
                pq.push( make_pair(-1 * new_cost, test_node) );
            }
        }
    }

    if(dist[to] == INF) return -1;
    else return dist[to];
}

int main() {
    // put inputs & initialization
    int T;
    scanf("%d", &T);
    while(T--){
        memset(map, 0, sizeof(map));
        vector<int> ans;
        int m, t, s, g, h, a, b, d;
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        while(m--){
            // input road
            scanf("%d %d %d", &a, &b, &d);
            map[a].push_back( make_pair(b,d) );
            map[b].push_back( make_pair(a,d) );
        }
        while(t--){
            // input candidates
            int can_input;
            scanf("%d",&can_input);

            // solution by Dijkstra Algorithm
            int d1 = Dijkstra(s,g) + Dijkstra(g,h) + Dijkstra(h,can_input);
            int d2 = Dijkstra(s,h) + Dijkstra(h,g) + Dijkstra(g,can_input);
            int d3 = Dijkstra(s,can_input);
            if(d3 == min(d1,d2))
                ans.push_back(can_input);
        }

        // sort answer vector
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans.at(i));
        printf("\n");
    }
}
