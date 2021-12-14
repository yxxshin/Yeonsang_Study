#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Handle carrying
void normalize(vector<int>& num) {
    num.push_back(0);
    
    for(int i = 0; i+1 < num.size(); i++) {
        if(num[i] < 0) {
            // This part is for Karatsuba Algorithm
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0)
        num.pop_back();
}

// O(n^2) multiply
// ex) multiply({3, 2, 1}, {6, 5, 4}) = 123 * 456 = 56088 = {8, 8, 0, 6, 5}
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

// a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max<int>(a.size(), b.size() + k));
    if(b.size() + k > a.size()) {
        for(int i = 0; i < b.size() + k - a.size(); i++) {
            a.push_back(0);
        }
    }
    for(int i = 0; i < b.size(); i++) {
        a[k+i] += b[i];
    }
    normalize(a);
}

// a -= b (assuring that a >= b)
void subFrom(vector<int>& a, const vector<int>& b) {
    a.resize(max<int>(a.size(), b.size()) + 1);
    for(int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    normalize(a);
}

// KARATSUBA Algorithm
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a);
    
    // Base Cases 
    if(an == 0 || bn == 0) return vector<int>();
    if(an <= 50) return multiply(a, b);

    // Divide and Conquer    
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    
    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);
    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);
    // z1 = (a0 + a1) * (b0 + b1) - z0 - z2
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    // ret = z0 + z1 * 10^half + z2 * 10^(half * 2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half * 2);
    return ret;
}



int main()
{
    // Testing multiply
    // 123 * 456 = 56088
    printf("O(n^2) Multiply Test :: 123 * 456 = 56088\n");
    vector<int> ans1 = multiply({3, 2, 1}, {6, 5, 4});
    for(int i = ans1.size() - 1; i >= 0; i--) {
        printf("%d", ans1[i]);
    }
    printf("\n\n");
    
    // Testing Karatsuba
    // 123456789 * 1111111 = 137174196282579
    printf("Karatsuba Test :: 123456789 * 1111111 = 137174196282579\n");
    vector<int> ans2 = karatsuba({9, 8, 7, 6, 5, 4, 3, 2, 1}, {1, 1, 1, 1, 1, 1, 1});
    for(int i = ans2.size() - 1; i >= 0; i--) {
        printf("%d", ans2[i]);
    }
    
    
}
