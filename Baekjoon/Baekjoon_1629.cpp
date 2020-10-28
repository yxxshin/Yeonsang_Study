#include <iostream>
using namespace std;

long long multiply_split(long long a, long long b, long long c) {  // a^b = ? (mod c)
    if(b == 0) return 1;

    if(b%2 == 1) return ((a%c) * (multiply_split(a, b/2, c)) % c * (multiply_split(a, b/2, c) % c)) % c;
    else return ((multiply_split(a, b/2, c) % c) * (multiply_split(a, b/2, c) % c)) % c;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    cout << multiply_split(A, B, C) << '\n';
}