#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} BTNode;


int len = 0;
char expr[5005];

BTNode* EXPR();
BTNode* makeNode(int c);
void print(BTNode *root);
int calc(BTNode* root);


int main(){
    BTNode* root = EXPR();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", expr);
        printf("%d\n", calc(root));
    }
}


BTNode* EXPR(){
    int data;
    char sym;
    scanf("%d", &data);
    if(data > len) len = data;

    scanf("%c", &sym);


    BTNode* root = makeNode(data);
    if(sym == '?'){
        root->left = EXPR();
        root->right = EXPR();
    }


    return root;

}


BTNode* makeNode(int c){
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

void print(BTNode* root){
    if(root == NULL) return;
    print(root->left);
    print(root->right);
    printf("%d", root->data);
}

int calc(BTNode* root){
    if(root->left != NULL && root->right != NULL){
        return expr[root->data - 1] - '0' ? calc(root->left) : calc(root->right);
    }

    return expr[root->data - 1] - '0';

}