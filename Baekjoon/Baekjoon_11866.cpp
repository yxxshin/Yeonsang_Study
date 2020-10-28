#include <iostream>
using namespace std;
#define size 10000000
int* arr = new int[size];
int start = 0;
int last = 0;
bool first = true;

int main(){
    int N, K;
    cin >> N >> K;

    //initialize
    last = N;
    for(int i = 0; i < N; i++)
        arr[i] = i + 1;

    //ordering
    cout << "<";
    while(last - start != 1) {
        for(int j = 0; j < K - 1; j++){
            arr[last] = arr[start];
            last++;
            start++;
        }
        if(!first) cout << ", ";
        if(first) first = false;
        cout << arr[start];

        start++;
    }
    if(!first) cout << ", ";
    cout << arr[start] << "> \n";

    delete[] arr;
}