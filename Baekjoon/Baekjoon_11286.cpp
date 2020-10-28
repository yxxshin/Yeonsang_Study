#include <cstdio>
#include <queue>

using namespace std;

int main() {
    // use priority_queue
    priority_queue<pair<int, int>> pq;
    // first: -abs(number), second: 1 or -1 => original number: first * second
    // why? default is greater<int> : big values come first
    int N, num;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &num);
        if(num == 0) {
            if(pq.empty()) {
                printf("0\n");
            } else {
                // queue is not empty
                printf("%d\n", pq.top().first * pq.top().second);
                pq.pop();
            }
        } else {
            if(num < 0) pq.push({num, 1});
            else pq.push({-num, -1});
        }
    }
}