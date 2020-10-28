#include <iostream>
#include <vector>
using namespace std;

long long int multiply_split(long long int a, long long int b, long long int c) {  // a^b = ? (mod c)
    if(b == 0) return 1;
    if(b%2 == 1) return ((a%c) * (multiply_split(a, b/2, c)) % c * (multiply_split(a, b/2, c) % c)) % c;
    else return ((multiply_split(a, b/2, c) % c) * (multiply_split(a, b/2, c) % c)) % c;
}

int main() {
    long long int N, K;
    cin >> N >> K;
    long long int DIVIDER = 1000000007;
    vector<long long int> index_factorial;
    index_factorial.push_back(1);  // 0! = 1
    long long int val = 1;

    for(long long int i = 1; i <= N; i++){
        val = (val * i) % DIVIDER;
        index_factorial.push_back(val);
    }
    long long int temp1 = (index_factorial[K] * index_factorial[N-K]) % DIVIDER;
    long long int temp2 = multiply_split(temp1, DIVIDER-2, DIVIDER) % DIVIDER;
    long long int temp3 = (index_factorial[N] * temp2) % DIVIDER;
    cout << temp3 << '\n';
}