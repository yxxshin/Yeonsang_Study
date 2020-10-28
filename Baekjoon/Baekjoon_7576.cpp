#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int map[1002][1002];
// to check 4 directions by 'for' loop
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M, ans = INT_MIN;
typedef struct Coord {
    int i;
    int j;
    int dist;
};
queue<Coord> q;

void bfs(){
    // use queue
    // bfs until arrival
    while(!q.empty()){
        // visit front node of q
        Coord temp = q.front();
        q.pop();

        // check 4 directions
        for(int i = 0; i < 4; i++){
            int next_i = temp.i + direction[i][0];
            int next_j = temp.j + direction[i][1];
            if(map[next_i][next_j] == 0 && next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
                // if valid, push node in queue and change value of map
                map[next_i][next_j] = 1;
                q.push( Coord{next_i, next_j, temp.dist + 1} );
                ans = max(ans, temp.dist + 1);
            }
        }
    }
}

int main() {
    // put inputs
    scanf("%d %d", &M, &N);

    // initialization
    memset(map, 0, sizeof(map));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // bfs (solution)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1)
                q.push( Coord{i, j, 0} );
            ans = 0;
        }
    }

    bfs();

    // check if problem is solvable
    bool isPossible = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                // cannot be solved
                isPossible = false;
                break;
            }
        }
    }

    // print answer
    if(isPossible) printf("%d\n", ans);
    else printf("-1\n");
}