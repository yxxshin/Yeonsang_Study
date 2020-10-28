#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(){
    stack<int> s;
    int N, T, temp;
    cin >> T;
    while(T--){
        std::string input;
        cin >> input;
        const char *c = input.c_str();
        if(strcmp(c,"push")==0){
            cin >> N;
            s.push(N);
        }
        if(strcmp(c,"pop")==0){
            if(s.empty()) cout << -1 << '\n';
            else {
                temp = s.top();
                cout << temp << '\n';
                s.pop();
            }
        }
        if(strcmp(c,"size")==0){
            temp = s.size();
            cout << temp << '\n';
        }
        if(strcmp(c,"empty")==0){
            cout << (s.empty() ? 1 : 0 ) << '\n';
        }
        if(strcmp(c,"top")==0){
            if(s.empty()) cout << -1 << '\n';
            else {
                temp = s.top();
                cout << temp << '\n';
            }
        }
    }

}