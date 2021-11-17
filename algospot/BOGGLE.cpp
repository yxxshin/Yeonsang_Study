#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int direction[8][2] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };
bool isExist;
bool visited[6][6][11]; // visited[x][y][idx]: Is the case 'board[x][y] is the idx'th char of target' able? 
char board[6][6];
char target[11];

void DP(int x, int y, int from) {
    // If already visited, exit (Dynamic Programming)
    if(visited[x][y][from]) {
        return;
    }
    
    visited[x][y][from] = true;
    // Check if the char matches
    if(board[x][y] != target[from]) {
        return;
    }
    
    // If the word is found,
    if(from == strlen(target)-1) {
        isExist = true;
        return;
    }
    
    // Then, test 8 directions from (x, y)
    for(int i = 0; i < 8; i++) {
        int nextX = x + direction[i][0];
        int nextY = y + direction[i][1];
        if(nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5) {
            // Test the next level
            DP(nextX, nextY, from+1);
        }
    }
}

void Solve() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            DP(i, j, 0);
        }
    }
    
    if(isExist) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int C, N;
    scanf("%d", &C);
    while(C--) {
        // Input Boggle board
        for(int i = 0; i < 5; i++) {
            scanf("%s", board[i]);
        }
        
        scanf("%d", &N);
        while(N--) {
            memset(visited, 0, sizeof(visited));    // Initialize to all-zeros
            isExist = false;
            
            scanf("%s", target);
            printf("%s ", target);
            
            // Using Dynamic Programming
            Solve();
        }
    }
}


