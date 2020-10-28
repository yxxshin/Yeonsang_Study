#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long int N;
int k;

int main() {
    scanf("%d",&N);
    scanf("%d",&k);

    long long int count = 0;
    long long int left = 1, right = N * N;
    long long int middle, answer;
    while(left <= right) {
        count = 0;
        middle = (left + right) / 2;

        // count how many numbers are lower than middle
        for(long long int i = 1; i <= N; i++){
            count += min(N, middle/i);
        }

        if(count < k){
            left = middle + 1;
        }

        else if(count >= k) {
            // the answer should be the minimum value
            answer = middle;
            right = middle - 1;
        }
    }

    printf("%lld\n",answer);
}