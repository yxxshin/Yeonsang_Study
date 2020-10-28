#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[1000];
    int* brr = new int[M];
    int start = 500;
    int last = 501 + N;
    int brr_count = 0;
    int answer = 0;

    //initialization
    for(int i = 1; i <= N; i++)
        arr[start + i] = i;
    for(int i = 0; i < M; i++)
        cin >> brr[i];

    //ordering
    while(brr_count < M) {
        // find the location of the next popping number
        int index_finding = 0;
        for(int i = start + 1; i < last; i++) {
            if(arr[i] == brr[brr_count]) {
                index_finding = i;
                break;
            }
        }

        // compare which way is faster
        // when action 2 is faster
        if(index_finding - start - 1 < last - index_finding) {
            int num_for = index_finding - start - 1;
            for(int i = 0; i < num_for; i++) {
                arr[last] = arr[start + 1];
                start++;
                last++;
                answer++;
            }
            start++; // pop_front
            brr_count++;
        }

            // when action 3 is faster or same
        else {
            int num_for = last - index_finding;
            for(int i=0; i < num_for ; i++ ) {
                arr[start] = arr[last - 1];
                start--;
                last--;
                answer++;
            }
            start++; // pop_front
            brr_count++;
        }
    }

    cout << answer << '\n';

}