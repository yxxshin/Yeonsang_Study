#include <cstdio>
#define MAX_NODE 26
using namespace std;

typedef struct Node {
    int left;
    int right;
};
int N;
Node tree[MAX_NODE+2];

// char to int
int ctoi(char c) {
    return c - 'A';
}
// int to char
char itoc(int n) {
    return n + 'A';
}

void visit(int node){
    if(node != ctoi('.')) {
        printf("%c",itoc(node));
    }
}

void preorderTraversal(int name) {
    if(name != ctoi('.')){
        visit(name);
        preorderTraversal(tree[name].left);
        preorderTraversal(tree[name].right);
    }
}

void inorderTraversal(int name){
    if(name != ctoi('.')){
        inorderTraversal(tree[name].left);
        visit(name);
        inorderTraversal(tree[name].right);
    }
}

void postorderTraversal(int name){
    if(name != ctoi('.')) {
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
        char node, left, right;
        scanf("%c %c %c", &node, &left, &right);
        tree[ctoi(node)].left = ctoi(left);
        tree[ctoi(node)].right = ctoi(right);
    }

    // print answers
    preorderTraversal(ctoi('A'));
    printf("\n");
    inorderTraversal(ctoi('A'));
    printf("\n");
    postorderTraversal(ctoi('A'));
    printf("\n");
}