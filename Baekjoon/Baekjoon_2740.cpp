#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

int main() {
    cin >> N >> M;
    vector<vector<int>> A, B;

    for(int i = 0; i < N; i++){
        vector<int> temp;
        int num;
        for(int j = 0; j < M; j++){
            cin >> num;
            temp.push_back(num);
        }
        A.push_back(temp);
    }

    cin >> M >> K;
    for(int i = 0; i < M; i++){
        int num;
        vector<int> temp;
        for(int j = 0; j < K; j++){
            cin >> num;
            temp.push_back(num);
        }
        B.push_back(temp);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int val = 0;
            for(int k = 0; k < M; k++) {
                val += A[i][k] * B[k][j];
            }
            cout << val << " ";
        }
        cout << '\n';
    }
}