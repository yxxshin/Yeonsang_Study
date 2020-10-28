#include <iostream>
using namespace std;

int arr[2188][2188];
int counter[3] = {0,};   // count[0]: -1, count[1]: 0, count[2]: 1의 개수

bool isSame(int n, int first, int second) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[first + i][second + j] != arr[first][second])
                return false;
        }
    }
    return true;
}

void Trippletree(int n, int first, int second) {
    if(isSame(n, first, second)){
        counter[arr[first][second] + 1]++;
        return;
    }
    else {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) {
                Trippletree(n/3, first + i * n/3, second + j * n/3);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    Trippletree(N, 0, 0);

    for(int i = 0; i < 3; i++)
        cout << counter[i] << '\n';
}