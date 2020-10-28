#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    char s[105];
    bool isNo;
    stack<char> st;

    while (1) {
        isNo = false;
        while (!st.empty()) {	// empty stack
            st.pop();
        }

        for (int i = 0; i < 105; i++)		// empty s
            s[i] = '\0';

        cin.getline(s, 105);		// input

        if (strcmp(s, ".") == 0) return 0;	// program exit
        else {
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '(' || s[i] == '[')
                    st.push(s[i]);	// save open-parenthesis at stack

                    // if pair matches, pop the opening one from the stack
                else if (s[i] == ')') {
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else {
                        isNo = true;
                        break;
                    }
                }
                else if (s[i] == ']') {
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else {
                        isNo = true;
                        break;
                    }
                }
            }
            if (!isNo && st.empty()) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }

    }
}