#include <iostream>
#include <cstring>
using namespace std;

int dp[21][21][21];

int dpFunc(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20) {
        return dpFunc(20, 20, 20);
    }
    else {
        // Already calculated once
        if(dp[a][b][c] != -1) {
            return dp[a][b][c];
        }
        // Not calculated yet: calculate
        else {
            int temp;
            if(a < b && b < c)
                temp = dpFunc(a, b, c - 1) + dpFunc(a, b - 1, c - 1) - dpFunc(a, b - 1, c);
            else
                temp = dpFunc(a-1, b, c) + dpFunc(a-1, b-1, c) + dpFunc(a-1, b, c-1) - dpFunc(a-1, b-1, c-1);
            dp[a][b][c] = temp;
            return temp;
        }
    }
}

int main() {
    // Initialization
    int a, b, c, ans;
    memset(dp, -1, sizeof(dp));     // if no value, dp = -1

    // Solution (DP)
    while(true) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        else {
            ans = dpFunc(a, b, c);
            cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << endl;
        }
    }
}