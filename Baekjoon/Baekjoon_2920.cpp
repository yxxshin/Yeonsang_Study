#include <cstdio>

int main() {
    int arr[8];
    for(int i = 0; i < 8; i++){
        scanf("%d", &arr[i]);
    }
    bool isAsc = true, isDesc = true;

    for(int i = 0; i < 8; i++) {
        if(arr[i] != i+1) {
            isAsc = false;
            break;
        }
    }
    for(int i = 0; i < 8; i++) {
        if(arr[i] != 8-i) {
            isDesc = false;
            break;
        }
    }

    if(isAsc) printf("ascending\n");
    else if(isDesc) printf("descending\n");
    else printf("mixed\n");
}