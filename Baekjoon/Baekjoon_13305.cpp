#include <cstdio>
#define MAX_N 100000

int N, road[MAX_N+3], gas[MAX_N+3];

int main() {
    // Initialization: save inputs
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++) {
        scanf("%d", &road[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &gas[i]);
    }

    long long totalMoney = 0;     // total money
    int gasVal = gas[0];   // lowest gas value until now (Greedy Algorithm)
    int roadNum = 0;       // road number (0 to N-1)
    while(true) {
        totalMoney += (long long)gasVal * road[roadNum];
        roadNum++;
        if(gas[roadNum] < gasVal) {
            // Greedy: Use the new gas value from now on
            gasVal = gas[roadNum];
        }
        if(roadNum == N) {
            // Finish Algorithm
            break;
        }
    }

    printf("%lld\n", totalMoney);

}