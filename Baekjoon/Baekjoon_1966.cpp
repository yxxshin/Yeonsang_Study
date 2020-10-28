#include <iostream>
using namespace std;

int main() {
    int test_case, N, M;
    bool answer_printed = false;
    cin >> test_case;

    while(test_case--){
        cin >> N >> M;
        // initialization
        int* arr = new int[1000000];
        int start = 0, last = N;
        int count = 1;
        int max_imp = 0;
        for(int i=0; i<N; i++) {
            cin >> arr[i];
            if(arr[i] > max_imp) max_imp = arr[i];
        }
        // ordering
        while(last - start != 1){
            // pop_and_push_it_back
            if(arr[start] != max_imp) {
                // moving M
                if(start == M) M = last;
                arr[last] = arr[start];
                start++;
                last++;
                continue;
            }

                // pop max_importance
            else if(arr[start] == max_imp) {
                // answer choice
                if(start == M) {
                    cout << count << '\n';
                    answer_printed = true;
                    break;
                }
                    // not the answer choice
                else {
                    count++;
                    start++;
                    // find the next max_imp
                    max_imp = 0;
                    for(int j = start; j < last; j++) if(arr[j] > max_imp) max_imp = arr[j];
                    continue;
                }
            }
        }
        // only one input
        if(!answer_printed) cout  << count << '\n';
        answer_printed = false;
        delete[] arr;
    }
}