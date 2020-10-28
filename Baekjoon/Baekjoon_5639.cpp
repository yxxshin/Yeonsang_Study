#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> preorder;

void make_tree(int start, int end){
    // if not a tree (finished finding) : skip
    if(start > end)
        return;

    // first number is root
    int root = preorder[start];

    // left sub-tree is all smaller than root, and right sub-tree is all bigger than root
    int divide = end+1; // first number's place which is bigger than root. if nothing : end+1
    for(int i = start; i <= end; i++){
        if(preorder[i] > root) {
            divide = i;
            break;
        }
    }

    // divide into two sub-trees based on 'divide'
    make_tree(start+1, divide-1);
    make_tree(divide,end);
    printf("%d\n",root);
}

int main() {
    // save inputs
    int temp;
    while(scanf("%d", &temp) != EOF) {
        preorder.push_back(temp);
    }
    make_tree(0,preorder.size()-1);
}