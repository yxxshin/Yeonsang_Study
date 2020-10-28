#include <iostream>
using namespace std;
int arr[65][65];

void Quadtree(int n, int first, int second) {
    bool isZero = false;
    bool isOne = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[first+i][second+j] == 0) isZero = true;
            else if(arr[first+i][second+j] == 1) isOne = true;
        }
    }
    if(isZero && isOne) {
        cout << "(";
        Quadtree(n/2, first, second);
        Quadtree(n/2, first, second + n/2);
        Quadtree(n/2, first + n/2, second);
        Quadtree(n/2, first + n/2, second + n/2);
    }
    else if(isZero == false) {
        cout << "1";
        return;
    }
    else if(isOne == false) {
        cout << "0";
        return;
    }
    cout << ")";
}

int main() {
    int N;
    cin >> N;
    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            arr[i][j] = (int)(c-'0');
        }
    }
    Quadtree(N, 0, 0);
}