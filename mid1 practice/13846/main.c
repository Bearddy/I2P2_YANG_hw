#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    long long int data;
    struct _Node *left, *right;
} BTNode;

long long int n;
BTNode* root = NULL;

void solve(int, BTNode*);
BTNode* makeNode(int );
void print(BTNode*, int);



int main(){
    scanf("%lld", &n);
    for(long long int i = 0; i < n; i++){
        long long input = 0;
        scanf("%lld", &input);
        solve(input, root);
    }

    print(root, 1);
}


void solve(int input, BTNode *node){
    if(node == NULL) root = makeNode(input);
    else{
        if(input <= node->data){
            if(node->left == NULL) node->left = makeNode(input);
            else solve(input, node->left);
        }
        else{
            if(node->right == NULL) node->right = makeNode(input);
            else solve(input, node->right);
        }

    }

}


BTNode* makeNode(int c){
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

void print(BTNode* root, int prt){
    if(root == NULL) return;

    print(root->left, 0);
    print(root->right, 0);
    printf("%lld", root->data);
    prt ? printf("\n") : printf(" ");


}

