#include <cstdio>
#include <vector>
#define MAX_NODE 100000
using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;
int place[MAX_NODE+2];

void make_tree(int inorder_start, int inorder_end, int postorder_start, int postorder_end){
    // it isn't a tree : skip
    if(inorder_start > inorder_end || postorder_start > postorder_end)
        return;

    // last number of postorder is "root node"
    int root = postorder[postorder_end];
    int root_place = place[root];

    // print root (preorderTraversal)
    printf("%d ", root);

    // make next two trees (left / right based on root_place)
    make_tree(inorder_start, root_place - 1, postorder_start, postorder_start + root_place - inorder_start - 1);
    make_tree(root_place + 1, inorder_end, postorder_start + root_place - inorder_start, postorder_end - 1);
}

int main() {
    // save inputs
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        inorder.push_back(temp);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        postorder.push_back(temp);
    }
    for(int i = 0; i < N; i++){
        place[inorder[i]] = i;
    }
    // make tree ( answer printed )
    make_tree(0, N-1, 0, N-1);
}