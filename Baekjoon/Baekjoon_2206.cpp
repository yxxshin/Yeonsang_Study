#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[1002][1002];
int visit[1002][1002];  // 0: not visited, 1: usedWall = false, -1: usedWall = true
// to check 4 directions by 'for' loop
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
typedef struct Coord {
    int i;
    int j;
    bool usedWall;
    int dist;
};
queue<Coord> q;
bool canArrive = false;

void bfs(){
    // use queue
    // start from (0,0)
    visit[0][0] = 1;
    q.push( Coord{0,0,false,1} );

    // bfs until arrival
    while(!q.empty()){
        // visit front node of q
        Coord temp = q.front();

        // if arrived final destination
        if(temp.i == N-1 && temp.j == M-1){
            canArrive = true;
            printf("%d\n", temp.dist);
            break;
        }
        q.pop();

        // better case exist (not using breakWall) : delete
        if(temp.usedWall && visit[temp.i][temp.j] == 1) continue;

        // check 4 directions
        for(int i = 0; i < 4; i++){
            int next_i = temp.i + direction[i][0];
            int next_j = temp.j + direction[i][1];
            if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
                // not breaking wall
                if(map[next_i][next_j] == 0) {
                    // if valid, push node in queue and check 'visited'
                    // not used breakWall
                    if(!temp.usedWall && visit[next_i][next_j] != 1) {
                        visit[next_i][next_j] = visit[temp.i][temp.j];
                        q.push( Coord{next_i, next_j, temp.usedWall, temp.dist + 1} );
                    }
                        // used breakWall
                    else if(temp.usedWall && visit[next_i][next_j] == 0) {
                        visit[next_i][next_j] = visit[temp.i][temp.j];
                        q.push( Coord{next_i, next_j, temp.usedWall, temp.dist + 1} );
                    }
                }
                // breaking wall
                if(map[next_i][next_j] == 1 && !temp.usedWall && visit[next_i][next_j] == 0) {
                    visit[next_i][next_j] = -1;
                    q.push( Coord{next_i, next_j, true, temp.dist + 1} );
                }
            }
        }
    }
}

int main() {
    // put inputs
    scanf("%d %d", &N, &M);

    // initialization
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    // bfs (solution)
    bfs();
    if(!canArrive) printf("-1\n");
}