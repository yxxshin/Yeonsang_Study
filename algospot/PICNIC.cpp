#include <stdio.h>
#include <cstring>

bool friends[11][11];
int n, m;

int countPairings(bool left[10]) {
    // Find the fastest 'number' which is not paired yet
    int firstOne = -1;
    for(int i = 0; i < n; i++) {
        if(!left[i]) {
            firstOne = i;
            break;
        }
    }
    
    // If every student is paired, exit (found one case)
    if(firstOne == -1) {
        return 1;
    }
    
    int res = 0;
    // Select firstOne's pair
    for(int i = firstOne + 1; i < n; i++) {
        if(!left[i] && friends[firstOne][i]) {
            left[firstOne] = left[i] = true;
            res += countPairings(left);        // Recursion
            left[firstOne] = left[i] = false;
        }
    }
    return res;
}


int main()
{
    int C;
    bool left[10];
    scanf("%d", &C);
    while(C--){
        memset(friends, 0, sizeof(friends));
        memset(left, 0, sizeof(left));
        scanf("%d %d", &n, &m);
        
        while(m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            friends[a][b] = true;
            friends[b][a] = true;
        }
        
        printf("%d\n", countPairings(left));
    }
}

