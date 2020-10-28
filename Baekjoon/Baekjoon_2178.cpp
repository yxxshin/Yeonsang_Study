#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[102][102];
int visit[102][102];
// to check 4 directions by 'for' loop
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
typedef struct Coord {
    int x;
    int y;
    int dist;
};
queue<Coord> q;

void bfs(){
    // use queue
    // start from (0,0)
    visit[0][0] = 1;
    q.push( Coord{0,0,1} );

    // bfs until arrival
    while(!q.empty()){
        // visit front node of q
        Coord temp = q.front();

        // if arrived final destination
        if(temp.x == M-1 && temp.y == N-1){
            printf("%d\n", temp.dist);
            break;
        }
        q.pop();

        // check 4 directions
        for(int i = 0; i < 4; i++){
            int next_x = temp.x + direction[i][0];
            int next_y = temp.y + direction[i][1];
            if(map[next_x][next_y] == 1 && next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && visit[next_x][next_y] != 1) {
                // if valid, push node in queue and check 'visited'
                visit[next_x][next_y] = 1;
                q.push( Coord{next_x, next_y, temp.dist + 1} );
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
            scanf("%1d", &map[j][i]);
        }
    }

    // bfs (solution)
    bfs();
}