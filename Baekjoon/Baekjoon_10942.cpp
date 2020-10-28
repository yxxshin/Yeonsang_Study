#include <cstdio>
#include <cstring>

using namespace std;

int arr[2002];
// dp[S][E]: check if arr[S] to arr[E] is pelindrome
// dp = -1 : not visited, 0 : not pelindrome, 1 : pelindrome
int dp[2002][2002];


void func(int S, int E){
    int s = S, e = E;
    while(s <= e && s >= S && e <= E){
        // one number : pelindrome
        if( s == e ) {
            dp[s][e] = 1;
            s--;
            e++;
            continue;
        }

            // adjacent number : should be same
        else if( e - s == 1 ){
            if(arr[s] == arr[e]) {
                dp[s][e] = 1;
                s--;
                e++;
                continue;
            }
            else {
                dp[s][e] = 0;
                s--;
                e++;
                continue;
            }
        }

            // if we already visited dp[s][e], break
        else if(dp[s][e] != -1) break;

            // if we don't know dp[s+1][e-1] either
        else if(dp[s+1][e-1] == -1){
            s++;
            e--;
            continue;
        }

            // if arr[S+1] to arr[E-1] is pelindrome and arr[S]==arr[E], arr[S] to arr[E] is pelindrome
        else if( dp[s+1][e-1] == 1 && arr[s] == arr[e]) {
            dp[s][e] = 1;
            s--;
            e++;
            continue;
        }

            // else: not pelindrome
        else {
            dp[s][e] = 0;
            s--;
            e++;
            continue;
        }
    }

    // print
    if(dp[S][E] == 1)
        printf("1\n");
    else if(dp[S][E] == 0)
        printf("0\n");
}

int main() {
    // input
    int N, M;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&M);

    // solution
    memset(dp, -1, sizeof(dp)); // original value of dp is all -1

    while(M--){
        int S, E;
        scanf("%d %d", &S, &E);
        func(S, E);
    }
}