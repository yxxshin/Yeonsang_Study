#include <cstdio>
#define MAX_NODE 1000
using namespace std;

// Tree Order - int version
// input the number of nodes N first
// then, enter "node_num left_child right_child" for the next N lines
// if there is no child(left or right), enter 0 each
// the root number should be 1

typedef struct Node {
    int left;
    int right;
};
int N;
Node tree[MAX_NODE+2];

void visit(int node){
    if(node != 0) {
        printf("%d ",node);
    }
}

void preorderTraversal(int name) {
    if(name != 0){
        visit(name);
        preorderTraversal(tree[name].left);
        preorderTraversal(tree[name].right);
    }
}

void inorderTraversal(int name){
    if(name != 0){
        inorderTraversal(tree[name].left);
        visit(name);
        inorderTraversal(tree[name].right);
    }
}

void postorderTraversal(int name){
    if(name != 0) {
        postorderTraversal(tree[name].left);
        postorderTraversal(tree[name].right);
        visit(name);
    }
}

int main() {
    // save inputs
    char buffer;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%c", &buffer);   // collect '\n'
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        tree[node].left = left;
        tree[node].right = right;
    }

    // print answers
    preorderTraversal(1);
    printf("\n");
    inorderTraversal(1);
    printf("\n");
    postorderTraversal(1);
    printf("\n");
}