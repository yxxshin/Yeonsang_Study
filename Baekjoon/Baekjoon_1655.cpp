#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int N;
    // make two priority queues: max and min
    // max_pq is less<int>, min_pq is greater<int>
    // every numbers in min_pq are bigger than every numbers in max_pq
    // every time, max_pq.size() should be same or 1 bigger than min_pq.size()
    priority_queue<int, vector<int>, less<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    scanf("%d",&N);
    while(N--) {
        // get input
        int num;
        scanf("%d", &num);

        // push num
        if(max_pq.size() == min_pq.size()) {
            max_pq.push(num);
        }
        else min_pq.push(num);

        // sort
        if(!min_pq.empty() && max_pq.top() > min_pq.top()) {
            // swap the two top values
            int min_temp = min_pq.top();
            int max_temp = max_pq.top();
            min_pq.pop();
            max_pq.pop();
            min_pq.push(max_temp);
            max_pq.push(min_temp);
        }

        // print middle value: top of max_pq
        printf("%d\n", max_pq.top());
    }

}