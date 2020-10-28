#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, i, j, num, temp = 0;
    stack<int> st;
    vector<char> vec;	// save the result (+,-)
    vector<int> seq;
    cin >> n;

    // save the sequence in vector seq
    for (i = 0; i < n; i++) {
        cin >> j;
        seq.push_back(j);
    }

    for (num = 1; num <= n; num++) {
        st.push(num);
        vec.push_back('+');

        if (!st.empty() && st.top() == seq.at(temp)) {
            do {
                st.pop();
                vec.push_back('-');
                temp++;
            } while (!st.empty() && st.top() == seq.at(temp));
        }
    }

    if (!st.empty()) {
        cout << "NO" << '\n';
        return 0;
    }

    for (i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << '\n';
    }
}