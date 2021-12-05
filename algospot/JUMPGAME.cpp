#include <stdio.h>
#include <iostream>
#include <cstring>

int board[100][100];
int cache[100][100];
int n; 

bool jump(int y, int x) {
    // base cases
    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;
    
    // use a reference 'ret'
    int& ret = cache[y][x];
    
    if(ret != -1) return ret;
    
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main()
{
    
    int test_num;
    scanf("%d", &test_num);
    
    while(test_num--) {
        scanf("%d", &n);
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));
        
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++) {
                scanf("%d", &board[y][x]);
            }
        }
        
        // Solution by Dynamic Programming
        if(jump(0, 0)) printf("YES\n");
        else printf("NO\n");
    }
}
