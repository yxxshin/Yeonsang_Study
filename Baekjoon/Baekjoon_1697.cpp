#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 100000
using namespace std;

int visit[MAX+2];
int N, K;
queue< pair<int, int> > q;     // <location,time>

bool isValid(int val){
    if(val >= 0 && val <= MAX && visit[val] != 1)
        return true;
    else return false;
}

void bfs(){
    // use queue
    // bfs until arrival
    while(!q.empty()){
        // visit front node of q
        pair<int, int> temp = q.front();
        q.pop();

        // solved problem
        if(temp.first == K) {
            // found kid
            printf("%d\n", temp.second);
            break;
        }

        // check all locations which can be arrived from temp in 1 sec
        if(isValid(temp.first - 1)){
            visit[temp.first - 1] = 1;
            q.push(make_pair(temp.first - 1, temp.second + 1));
        }

        if(isValid(temp.first + 1)){
            visit[temp.first + 1] = 1;
            q.push(make_pair(temp.first + 1, temp.second + 1));
        }

        if(isValid(temp.first * 2)) {
            visit[temp.first * 2] = 1;
            q.push(make_pair(temp.first * 2, temp.second + 1));
        }
    }
}

int main() {
    // put inputs
    scanf("%d %d", &N, &K);

    // initialization
    memset(visit, 0, sizeof(visit));
    visit[N] = 1;
    q.push( make_pair(N,0) );
    bfs();
}