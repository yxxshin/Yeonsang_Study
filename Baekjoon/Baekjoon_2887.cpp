#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int N;
int ans = 0;

typedef struct Planet {
    int x;
    int y;
    int z;
    int num;
};

typedef struct Road {
    int p1_num;
    int p2_num;
    int len;
};

bool comp_x(Planet p1, Planet p2){
    return (p1.x < p2.x);
}

bool comp_y(Planet p1, Planet p2){
    return (p1.y < p2.y);
}

bool comp_z(Planet p1, Planet p2){
    return (p1.z < p2.z);
}

bool comp_num(Planet p1, Planet p2){
    return (p1.num < p2.num);
}

bool comp_road(Road r1, Road r2){
    return (r1.len < r2.len);
}

int parent[MAX_N+2];
vector<Planet> planets;
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
        if( find(map[j].p1_num) != find(map[j].p2_num)){
            merge(map[j].p1_num, map[j].p2_num);
            count++;
            ans += map[j].len;
        }
        // There should be N-1 roads at MST
        if(count == N-1)
            break;
    }
}

int main() {
    // inputs
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        planets.push_back(Planet{x,y,z,i});
    }

    // initialization
    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    // make map
    // sort by x and just push adjacent ones
    sort(planets.begin(), planets.end(), comp_x);

    for(int i = 0; i <= N-2; i++){
        map.push_back( {planets[i].num, planets[i+1].num, planets[i+1].x - planets[i].x} );
    }

    // sort by y and just push adjacent ones
    sort(planets.begin(), planets.end(), comp_y);
    for(int i = 0; i <= N-2; i++){
        map.push_back( {planets[i].num, planets[i+1].num, planets[i+1].y - planets[i].y} );
    }

    // sort by z and just push adjacent ones
    sort(planets.begin(), planets.end(), comp_z);
    for(int i = 0; i <= N-2; i++){
        map.push_back( {planets[i].num, planets[i+1].num, planets[i+1].z - planets[i].z} );
    }

    // sort originally and use Kruksal Algorithm
    sort(planets.begin(), planets.end(), comp_num);
    sort(map.begin(), map.end(), comp_road);
    Kruksal();

    // print answer
    printf("%d\n", ans);
}