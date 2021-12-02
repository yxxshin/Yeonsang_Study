#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int middle(vector<int> fence, int i, int k, int j) {
    // from fence[i] to fence[j], but fence[k] & fence[k+1] must be included
    int res, first = k, last = k + 1, height;
    height = min(fence[first], fence[last]);
    res = 2 * height;
    
    while(first > i || last < j) {
        if(first == i || (last != j) && (fence[first - 1] <= fence[last + 1])) {
            last++;
            if(fence[last] < height)
                height = fence[last];
            
            res = max(res, height * (last - first + 1));
        }
        
        else {
            first--;
            if(fence[first] < height)
                height = fence[first];
            
            res = max(res, height * (last - first + 1));
        }
    }
    
    return res;
    
}

int solve(vector<int> fence, int i, int j) {
    // from fence[i] to fence[j]
    if(i == j) {
        return fence[i];
    }
    
    int mid = (i + j) / 2;
    return max({solve(fence, i, mid), solve(fence, mid + 1, j), middle(fence, i, mid, j)});
}


int main()
{
    int test_num;
    scanf("%d", &test_num);
    while(test_num--) {
        int fence_num;
        vector<int> fence;
        scanf("%d", &fence_num);
        for(int i = 0; i < fence_num; i++) {
            int input;
            scanf("%d", &input);
            fence.push_back(input);
        }
        
        // Solution by Divide & Conquer
        printf("%d\n", solve(fence, 0, fence_num-1));
    }
}
