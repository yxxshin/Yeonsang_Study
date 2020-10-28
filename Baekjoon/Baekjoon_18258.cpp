#include <iostream>
#include <string>
using namespace std;
#define size 20000001

int* arr = new int[size];
int last = 0;
int start = 0;

void switch_string(string s){
    if(s == "push"){
        int num;
        cin >> num;
        arr[last] = num;
        last++;
    }

    else if(s == "pop") {
        if(last - start == 0) cout << -1 << '\n';
        else {
            cout << arr[start] << '\n';
            start++;
        }
    }

    else if(s == "size"){
        cout << last - start << '\n';
    }

    else if(s == "empty"){
        if(last - start == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    else if(s == "front"){
        if(last - start == 0) cout << -1 << '\n';
        else cout << arr[start] << '\n';
    }

    else if(s == "back"){
        if(last - start == 0) cout << -1 << '\n';
        else cout << arr[last - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        switch_string(s);
    }

    delete[] arr;
}