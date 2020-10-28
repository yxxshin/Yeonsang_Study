#include <iostream>
using namespace std;
#define size 5000001

int* arr = new int[size];
int start = 0;
int last = 0;

void pop() {
    start++;
}

void pop_and_push_back(){
    arr[last] = arr[start];
    last++;
    start++;
}

int main() {
    int N;
    cin >> N;
    //initialization
    last = N;
    for(int i = 0; i < N; i++) {
        arr[i] = i+1;
    }

    //ordering until one number lasts
    while(last - start != 1) {
        pop();
        pop_and_push_back();
    }

    cout << arr[start] << '\n';

}