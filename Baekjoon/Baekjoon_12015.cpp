#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // put inputs
    int N;
    scanf("%d",&N);

    int* arr = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }

    // use LIS vector
    vector<int> LIS;
    LIS.push_back(0);
    int len = 0;

    for(int i = 0; i < N; i++){
        // if next arr number is bigger than the biggest value in LIS
        if(arr[i] > LIS.back()){
            // push back(update)
            LIS.push_back(arr[i]);
            len++;
        }

            // if not: switch this value in the alright place
        else {
            // find the lower bound and switch: Binaray Search
            int left = 0, right = LIS.size(), middle;
            while(left < right) {
                middle = (left + right) / 2;
                if(LIS[middle] < arr[i]) left = middle + 1;
                else right = middle;
            }
            LIS[right] = arr[i];
        }
    }

    printf("%d\n",len);
}