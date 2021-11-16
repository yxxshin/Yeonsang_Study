#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int direction[8][2] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };
bool isExist;

void DFS(char board[][6], string target, int x, int y, int from) {
    // If the target is found, change the flag
    if(from == target.length()) {
        isExist = true;
    }
    
    // Else, test 8 directions from (x, y)
    for(int i = 0; i < 8; i++) {
        int nextX = x + direction[i][0];
        int nextY = y + direction[i][1];
        if(nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5) {
            if(board[nextX][nextY] == target[from]) {
                // Go to next level
                DFS(board, target, nextX, nextY, from+1);
            }
        }
    }
}

void Solve(char board[][6], string target) {
    isExist = false;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == target[0]) {
                // First letter is same, start DFS
                DFS(board, target, i, j, 1);
            }
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
        char board[6][6];
        for(int i = 0; i < 5; i++) {
            scanf("%s", board[i]);
        }
        
        scanf("%d", &N);
        while(N--) {
            // Using DFS for searching
            string target;
            cin >> target;
            Solve(board, target);
        }
    }
}

