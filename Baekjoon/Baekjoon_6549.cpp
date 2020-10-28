#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int n;
long long int arr[100002];
int main() {
    while(true) {
        scanf("%d",&n);
        // ending program
        if(n == 0) break;

        // initialization
        for(int i = 0; i < 100002; i++){
            arr[i] = 0;
        }

        // input histogram
        for(int i = 0; i < n; i++) {
            scanf("%d",&arr[i]);
        }

        // solution using <stack>
        stack<int> s;
        long long int ans = 0;

        for (int i = 0; i < n; i++) {
            // first step : fill the stack until the last one
            while(!s.empty() && arr[s.top()] > arr[i]) {
                long long int height = arr[s.top()];
                s.pop();
                int width = i;
                if (!s.empty()) {
                    width = (i - s.top() - 1);
                }
                if (ans < width*height) {
                    ans = width*height;
                }
            }
            s.push(i);
        }
        // second step : when first step finished but the stack is not empty
        while(!s.empty()) {
            long long int height = arr[s.top()];
            s.pop();
            long long int width = n;
            if (!s.empty()) {
                width = n-s.top()-1;
            }
            if (ans < width*height) {
                ans = width*height;
            }
        }
        printf("%lld\n",ans);
    }
}