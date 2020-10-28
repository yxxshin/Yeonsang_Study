#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#define INF 999999999
using namespace std;

typedef tuple<int,int,int> TUPLE;

int N, M;
int dp[102][10002];     // dp[i][j]: time going to i with cost j

int main() {
    int T, K;
    scanf("%d", &T);
    while(T--){

        bool isAns = false;
        scanf("%d %d %d", &N, &M, &K);
        // initialization
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                dp[i][j] = INF;
            }
        }

        vector<TUPLE> map[103];  // map[from].{ to, value, time }
        while(K--){
            int from, to, value, time;
            scanf("%d %d %d %d", &from, &to, &value, &time);
            map[from].push_back( make_tuple(to,value,time) );
        }

        // auto-ordered by time
        priority_queue<TUPLE,vector<TUPLE>,greater<TUPLE>> pq; // {time, to, value}
        pq.push({0,1,0});   // start

        while(!pq.empty()){
            // consider top of pq
            TUPLE temp = pq.top();
            int time_temp = get<0>(temp);
            int to_temp = get<1>(temp);
            int value_temp = get<2>(temp);
            pq.pop();

            // if arrived N
            if(to_temp == N){
                // arrived N within cost M, and minimum time (automatically ordered pq)
                isAns = true;
                printf("%d\n", time_temp);
                break;
            }

            // A better case is already saved in dp : skip
            if(dp[to_temp][value_temp] < time_temp)
                continue;

            // looking for next node
            for(int i = 0; i < map[to_temp].size(); i++){
                TUPLE next = map[to_temp].at(i);
                int to_next = get<0>(next);
                int value_next = get<1>(next);
                int time_next = get<2>(next);

                // if cost gets over M : skip
                if(value_temp + value_next > M)
                    continue;

                // if going to 'next' is a better case than the one originally saved in dp
                if(dp[to_next][value_temp + value_next] > time_temp + time_next) {
                    // change dp and push to pq
                    dp[to_next][value_temp + value_next] = time_temp + time_next;
                    pq.push(make_tuple(time_temp + time_next, to_next, value_temp + value_next));
                }
            }
        }
        // no way to go N
        if(!isAns)
            printf("Poor KCM\n");
    }
}