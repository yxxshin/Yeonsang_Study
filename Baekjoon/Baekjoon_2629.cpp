#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_WEIGHT 500
#define MAX_WEIGHT_NUM 30
#define MAX_WEIGHT_VAL 40000
#define MAX_TEST_NUM 7

int main() {
    // Initialization: save inputs
    int weight_num, test_num;
    int W[MAX_WEIGHT_NUM + 2], T[MAX_TEST_NUM + 2];
    scanf("%d", &weight_num);
    for(int i = 0; i < weight_num; i++){
        scanf("%d", &W[i]);
    }
    scanf("%d", &test_num);
    for(int i = 0; i < test_num; i++){
        scanf("%d", &T[i]);
    }

    // Using 2D-array for DP
    // if using 0th~ith weight can make weight j, DP[i][j] = true
    bool DP[MAX_WEIGHT_NUM+2][MAX_WEIGHT_VAL+2] = {false};
    DP[0][W[0]] = true;
    DP[0][0] = true;
    // Set values of array DP
    for(int i = 1; i < weight_num; i++) {
        for(int j = 0; j < MAX_WEIGHT_VAL; j++) {
            DP[i][j] = DP[i-1][j] or DP[i-1][std::abs(j+W[i])] or DP[i-1][std::abs(j-W[i])];
        }
    }

    for(int i = 0; i < test_num; i++) {
        if(DP[weight_num - 1][T[i]])
            printf("Y");
        else printf("N");
        if(i != test_num - 1)
            printf(" ");
    }
}