#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
int memory[100], cost[100];
int dp[10001];     // dp[i] : the max value of memory using cost i

int main() {
    // get inputs
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++){
        scanf("%d",&memory[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&cost[i]);
    }

    // make dp[i] all -1, to know if visited or not
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++){
        // consider about using c[i]
        // update from the back : prevent overlapping
        int temp_cost = cost[i];

        for(int j = 10000; j >= cost[i]; j--) {
            if(dp[j - temp_cost] == -1) {
                // not visited
                continue;
            }

            if(dp[j - temp_cost] + memory[i] > dp[j]) {
                // better condition : swap
                dp[j] = dp[j -temp_cost] + memory[i];
            }
        }

        if(dp[temp_cost] < memory[i]) {
            // when just using itself(i'th) is better : swap
            dp[temp_cost] = memory[i];
        }
    }

    // print answer: the smallest dp[i] which is bigger than M is the answer
    for(int i = 0; i < 10001; i++){
        if(dp[i] >= M) {
            printf("%d\n", i);
            break;
        }
    }

}