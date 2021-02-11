#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_LEN 300

typedef struct Knight {
    int X;
    int Y;
    int dist;
};

// 8 ways of Knight moving
int direction[8][2] = { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

int main() {
    int testNum;
    scanf("%d", &testNum);
    while(testNum--) {
        // Save inputs
        int boardLen, startX, startY, endX, endY;
        scanf("%d", &boardLen);
        scanf("%d %d", &startX, &startY);
        scanf("%d %d", &endX, &endY);

        // BFS Settings
        bool board[MAX_LEN+2][MAX_LEN+2]; // board[X][Y] = true if visited (X,Y)
        memset(board, false, sizeof(board));
        std::queue<Knight> q;
        q.push(Knight{startX, startY, 0});

        // Solve by BFS
        while(!q.empty()) {
            Knight topKnight = q.front();
            board[topKnight.X][topKnight.Y] = topKnight.dist;
            if(topKnight.X == endX && topKnight.Y == endY) {
                // Arrived at the destination
                printf("%d\n", topKnight.dist);
                break;
            }
            // push next 8 locations to queue (if valid)
            for(int i = 0; i < 8; i++) {
                int tempX = topKnight.X + direction[i][0];
                int tempY = topKnight.Y + direction[i][1];
                // check if valid location
                if(tempX >= 0 && tempX < boardLen && tempY >= 0 && tempY < boardLen) {
                    // only push when not visited before
                    if(!board[tempX][tempY]) {
                        q.push(Knight{tempX, tempY, topKnight.dist + 1});
                        board[tempX][tempY] = true; // check visited
                    }
                }
            }
            // pop the top Knight of queue
            q.pop();
        }
    }
}