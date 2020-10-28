#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 100
using namespace std;

int n;
double ans = 0;

typedef struct Star {
    double x;
    double y;
};

typedef struct Road {
    int s1_num;
    int s2_num;
    double len;
};

double distance(Star s1, Star s2){
    double d = pow(s1.x-s2.x,2) + pow(s1.y-s2.y,2);
    return sqrt(d);
}

bool comp_road(Road r1, Road r2){
    return (r1.len < r2.len);
}

int parent[MAX_N+2];
Star stars[MAX_N+2];
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
        if( find(map[j].s1_num) != find(map[j].s2_num)){
            merge(map[j].s1_num, map[j].s2_num);
            count++;
            ans += map[j].len;
        }
        // There should be n-1 roads at MST
        if(count == n-1)
            break;
    }
}

int main() {
    // inputs
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        stars[i] = Star{x,y};
    }

    // initialization
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    // make map
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            map.push_back( { i, j, distance(stars[i],stars[j]) } );
        }
    }

    // sort roads by "value" for Kruksal Algorithm
    sort(map.begin(), map.end(), comp_road);

    // Kruksal Algorithm
    Kruksal();

    // print answer
    printf("%lf\n", ans);
}