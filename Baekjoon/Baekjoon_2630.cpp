#include <iostream>
using namespace std;

int count_white = 0, count_blue = 0;

void split_func(int** arr, int size, int x_index, int y_index) {
    bool is_all_white = true;
    bool is_all_blue = true;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            if(arr[x_index + i][y_index + j] == 0) is_all_blue = false; // arr[index+i][index+j] is white
            else is_all_white = false;  // arr[index+i][index+j] is blue
        }
    }

    if(is_all_white) count_white++;
    else if(is_all_blue) count_blue++;
    else {
        split_func(arr, size/2, x_index, y_index);
        split_func(arr, size/2, x_index + size/2, y_index);
        split_func(arr, size/2, x_index, y_index + size/2);
        split_func(arr, size/2, x_index + size/2, y_index + size/2);
    }

}

int main() {
    int N;
    cin >> N;

    // Dynamic Memory Allocation
    int** arr = new int*[N];
    for(int i = 0; i < N; i++)
        arr[i] = new int[N];

    // input array
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // main action
    split_func(arr, N, 0, 0);
    cout << count_white << '\n';
    cout << count_blue << '\n';

    // Delete Memory
    for(int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
}