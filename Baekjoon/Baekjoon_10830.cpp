#include <iostream>
#include <vector>
using namespace std;

int N;

vector<vector<int>> multiply_matrix(vector<vector<int>> &v1, vector<vector<int>> &v2) {
    // calculate v1 * v2
    vector<vector<int>> ans;

    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int val = 0;
            for(int k = 0; k < N; k++){
                val += v1[i][k] * v2[k][j] % 1000;
            }
            val %= 1000;
            temp.push_back(val);
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<vector<int>> pow_matrix(vector<vector<int>> &v, long long int B){
    if(B == 1) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[i][j] %= 1000;
            }
        }
        return v;
    }
    else if(B % 2 == 0) {
        vector<vector<int>> temp1 = pow_matrix(v, B/2);
        vector<vector<int>> temp2 = multiply_matrix(temp1, temp1);
        return temp2;
    }
    else {
        vector<vector<int>> temp1 = pow_matrix(v, B/2);
        vector<vector<int>> temp2 = multiply_matrix(temp1, temp1);
        vector<vector<int>> temp3 = multiply_matrix(v, temp2);
        return temp3;
    }
}

void print(vector<vector<int>> &v) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    int num;
    long long int B;
    cin >> N >> B;

    // input array (arr)
    vector<vector<int>> arr;
    vector<int> temp;
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            cin >> num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }

    // multiply
    vector<vector<int>> ans;
    ans = pow_matrix(arr, B);

    // print
    print(ans);
}