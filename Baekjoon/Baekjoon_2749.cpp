#include <iostream>
#include <vector>
using namespace std;

int N = 2;

vector<vector<long long>> multiply_matrix(vector<vector<long long>> &v1, vector<vector<long long>> &v2) {
    // calculate v1 * v2
    vector<vector<long long>> ans;

    for(int i = 0; i < N; i++){
        vector<long long> temp;
        for(int j = 0; j < N; j++){
            long long int val = 0;
            for(int k = 0; k < N; k++){
                val += ((v1[i][k] % 1000000) * (v2[k][j] % 1000000)) % 1000000;
            }
            val %= 1000000;
            temp.push_back(val);
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<vector<long long>> pow_matrix(vector<vector<long long>> &v, long long int B){
    if(B == 1) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                v[i][j] %= 1000000;
            }
        }
        return v;
    }
    else if(B % 2 == 0) {
        vector<vector<long long>> temp1 = pow_matrix(v, B/2);
        vector<vector<long long>> temp2 = multiply_matrix(temp1, temp1);
        return temp2;
    }
    else {
        vector<vector<long long>> temp1 = pow_matrix(v, B/2);
        vector<vector<long long>> temp2 = multiply_matrix(temp1, temp1);
        vector<vector<long long>> temp3 = multiply_matrix(v, temp2);
        return temp3;
    }
}

int main() {
    long long int n;
    cin >> n;

    // input array [[1,1],[1,0]]
    vector<vector<long long>> arr;
    vector<long long> temp;
    temp.push_back(1);
    temp.push_back(1);
    arr.push_back(temp);
    temp.pop_back();
    temp.push_back(0);
    arr.push_back(temp);

    // multiply
    if(n <= 1) {
        cout << n << '\n';
        return 0;
    }
    vector<vector<long long>> ans;
    ans = pow_matrix(arr, n-1);

    // print
    cout << ans[0][0] << '\n';

}