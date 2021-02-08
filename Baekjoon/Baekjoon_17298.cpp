#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#define MAX_N 1000000

int NGE[MAX_N+2];

int main() {

    // Initialization
    int N;
    scanf("%d", &N);
    std::pair<int, int> *pairArr = new std::pair<int, int>[N+2];      // save <i, Ai>
    for(int i = 1; i <= N; i++) {
        pairArr[i].first = i;
        scanf("%d", &pairArr[i].second);
    }

    // Initialize array NGE to -1
    memset(NGE, -1, sizeof(NGE));

    // Use a stack to solve problem
    std::stack<std::pair<int, int>> s;

    // Push pairs to the stack
    for(int i = 1; i <= N; i++) {
        // Pop every member in stack while pairArr[i].second is smaller than s.top()
        if(!s.empty()) {

            while(pairArr[i].second > s.top().second) {
                std::pair<int, int> topPair = s.top();
                s.pop();
                // Update topPair's NGE info
                NGE[topPair.first] = pairArr[i].second;
                if(s.empty()) break;
            }
        }
        s.push(pairArr[i]);
    }

    // Print answer
    for(int i = 1; i <= N; i++) {
        printf("%d ", NGE[i]);
    }

    delete[] pairArr;
}