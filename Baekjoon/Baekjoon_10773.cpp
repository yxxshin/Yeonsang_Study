#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K, temp, res = 0;
    stack<int> st;
    cin >> K;
    while (K--) {
        cin >> temp;
        if (temp != 0)
            st.push(temp);
        else if (temp == 0)
            st.pop();
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}