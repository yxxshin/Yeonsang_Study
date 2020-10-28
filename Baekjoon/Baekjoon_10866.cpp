#include <iostream>
#include <string>
using namespace std;

int* arr = new int[100010];
int start = 5000;
int last = 5001;

void deque_func(string s) {
    int num = 0;
    if(s == "push_front") {
        cin >> num;
        arr[start] = num;
        start--;
    }

    else if(s == "push_back") {
        cin >> num;
        arr[last] = num;
        last++;
    }

    else if(s == "pop_front") {
        if(last - start == 1) cout << -1 << '\n';
        else {
            cout << arr[start + 1] << '\n';
            start++;
        }
    }

    else if(s == "pop_back") {
        if(last - start == 1) cout << -1 << '\n';
        else {
            cout << arr[last - 1] << '\n';
            last--;
        }
    }

    else if(s == "size") {
        cout << last - start - 1 << '\n';
    }

    else if(s == "empty") {
        if(last - start == 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    else if(s == "front"){
        if(last - start == 1) cout << -1 << '\n';
        else cout << arr[start + 1] << '\n';
    }

    else if(s == "back"){
        if(last - start == 1) cout << -1 << '\n';
        else cout << arr[last - 1] << '\n';
    }
}

int main() {
    int N;
    cin >> N;


    while(N--){
        string input_s;
        cin >> input_s;
        deque_func(input_s);
    }

    delete[] arr;
}