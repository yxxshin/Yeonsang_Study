#include <stdio.h>
#include <cstring>

int H, W;
char input_board[20][20];

int coverBoard(bool board[20][20]) {
    // Always consider the top leftmost space
    
    // Finding the top leftmost location
    int leftX = -1, leftY = -1;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board[i][j]){
                leftY = i;
                leftX = j;
                break;
            }
        }
        if(leftX != -1 && leftY != -1) {
            break;
        }
    }
    
    // Every place is full
    if(leftX == -1 && leftY == -1) {
        // Found one answer
        return 1;
    }
    
    int res = 0;
    // Otherwise, try the 4 cases
    if(board[leftY+1][leftX] && board[leftY][leftX+1]) {
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY][leftX+1] = false;
        res += coverBoard(board);
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY][leftX+1] = true;
    }
    
    if(board[leftY][leftX+1] && board[leftY+1][leftX+1]) {
        board[leftY][leftX] = board[leftY][leftX+1] = board[leftY+1][leftX+1] = false;
        res += coverBoard(board);
        board[leftY][leftX] = board[leftY][leftX+1] = board[leftY+1][leftX+1] = true;
    }
    
    if(board[leftY+1][leftX] && board[leftY+1][leftX+1]) {
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY+1][leftX+1] = false;
        res += coverBoard(board);
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY+1][leftX+1] = true;
    }
    
    if(board[leftY+1][leftX] && board[leftY+1][leftX-1]) {
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY+1][leftX-1] = false;
        res += coverBoard(board); 
        board[leftY][leftX] = board[leftY+1][leftX] = board[leftY+1][leftX-1] = true;
    }
    
    return res;
    
}

int main()
{
    int test_num;
    scanf("%d", &test_num);
    while(test_num--) {
        // Initialize
        bool board[20][20];
        memset(input_board, 0, sizeof(input_board));
        memset(board, 0, sizeof(board));
        
        scanf("%d %d", &H, &W);
        
        for(int i = 0; i < H; i++) {
            scanf("%s", input_board[i]);
            for(int j = 0; j < W; j++) {
                if(input_board[i][j] == '.') {
                    board[i][j] = true;
                }
            }
        }
        
        printf("%d\n", coverBoard(board));
    }
}
