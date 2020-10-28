#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, n;
    string p, input_array;
    cin >> T;

    while(T--){
        //test case start
        cin >> p;
        cin >> n;
        cin >> input_array;

        int* arr = new int[400010];
        int arr_count = 1;
        int start = 0;
        int last = n + 1;
        bool is_error = false;
        bool is_reverse = false;

        // input array
        int k = 1;
        while(input_array[k] != '\0') {
            int x = 0;
            while(input_array[k] >= '0' && input_array[k] <= '9') {
                x *= 10;
                x += int(input_array[k] - '0');
                k++;
            }
            if( x != 0 ){
                arr[arr_count] = x;
                arr_count++;
            }
            k++;
        }

        // do actions
        for(int j = 0; j < p.length(); j++) {
            if(p[j] == 'R'){
                // check if it is reverse or not
                is_reverse = !is_reverse;
            }

            else if(p[j] == 'D'){
                // delete first number or last number
                // if array is empty
                if(last - start == 1) {
                    is_error = true;
                    break;
                }
                    // if array is not empty:
                else {
                    if(is_reverse) last--;
                    else if(!is_reverse) start++;
                }
            }
        }

        if(is_error) cout << "error" << '\n';
        else {
            cout << "[";
            if(!is_reverse){
                for(int i = start + 1; i < last - 1; i++)
                    cout << arr[i] << ",";
                if(last - start != 1) cout << arr[last-1];
                cout << "]" << '\n';
            }
            else if(is_reverse){
                for(int i = last - 1; i > start + 1; i--)
                    cout << arr[i] << ",";
                if(last - start != 1) cout << arr[start + 1];
                cout << "]" << '\n';
            }

        }
        is_error = false;
        p = "";
    }
}