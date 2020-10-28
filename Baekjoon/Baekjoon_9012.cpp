#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    int T, value;
    stack<char> st;
    char s[50];

    cin >> T;
    while (T--) {
        value = 0;
        cin >> s;
        for (int i = 0; i < strlen(s); i++)
            st.push(s[i]);	// save at stack

        while (!st.empty()) {
            if (st.top() == ')') {
                value++;
                st.pop();
            }

            else if (st.top() == '(') {
                value--;
                st.pop();
            }

            if (value < 0) {
                break;
            }
        }
        if (st.empty() && value == 0) cout << "YES" << endl;
        else cout << "NO" << endl;

        while (!st.empty()) {
            st.pop();
        }
    }
}