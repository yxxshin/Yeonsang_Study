#include <cstdio>
#define MAX_M 30

// arr[n][k] = nCk
int arr[MAX_M + 3][MAX_M + 3];

int main() {

    // Calculate Arr by Recurrence Relation
    for(int i = 1; i <= 30; i++){
        for(int j = 0; j <= 30; j++) {
            if(j==0 || i==j) {
                arr[i][j] = 1;
                continue;
            }
            else {
                // nCr = n-1Cr-1 + n-1Cr
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    int T;
    scanf("%d", &T);
    int N, M;
    while(T--) {
        scanf("%d %d", &N, &M);
        // the answer is MCN
        printf("%d\n", arr[M][N]);
    }
}