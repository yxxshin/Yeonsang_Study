#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 9999;

bool check(int clocks[16]) {
    bool flag = true;
    for(int i = 0; i < 16; i++) {
        if(clocks[i] != 12)
            flag = false;
    }
    return flag;
}

void set(int clocks[16], vector<int> clock_nums) {
    for(auto it = std::begin(clock_nums); it != std::end(clock_nums); it++) {
        if(clocks[*it] == 12)
            clocks[*it] = 0;
        clocks[*it] += 3;
    }
}

void switchClock(int clocks[16], int switch_num) {
    switch(switch_num) {
        case 0:
            set(clocks, {0, 1, 2});
            break;
        case 1:
            set(clocks, {3, 7, 9, 11});
            break;
        case 2:
            set(clocks, {4, 10, 14, 15});
            break;
        case 3:
            set(clocks, {0, 4, 5, 6, 7});
            break;
        case 4:
            set(clocks, {6, 7, 8, 10, 12});
            break;
        case 5:
            set(clocks, {0, 2, 14, 15});
            break;
        case 6:
            set(clocks, {3, 14, 15});
            break;
        case 7:
            set(clocks, {4, 5, 7, 14, 15});
            break;
        case 8:
            set(clocks, {1, 2, 3, 4, 5});
            break;
        case 9:
            set(clocks, {3, 4, 5, 9, 13});
            break;
    }
}

int solve(int clocks[16], int sw) {
    // Finished switching
    if(sw == 10) return (check(clocks) ? 0 : INF);
    
    // Try EVERY case of switching,
    /// since the order doesn't care & each sw can be pushed up to 3 times
    int res = INF;
    for(int count = 0; count < 4; count++) {
        res = min(res, count + solve(clocks, sw + 1));
        switchClock(clocks, sw);
    }
    
    return res;
}


int main()
{
    int test_num;
    int clocks[16];
    
    scanf("%d", &test_num);
    while(test_num--) {
        
        memset(clocks, 0, sizeof(clocks));
        
        for(int i = 0; i < 16; i++)
            scanf("%d", &clocks[i]);
     
        int ans = solve(clocks, 0);
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
}
