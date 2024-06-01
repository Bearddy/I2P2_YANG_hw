#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

char sym[NUMSYM];

typedef struct _Node {
    char data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void print(BTNode *root);


int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    scanf("%s", expr);
    pos = strlen(expr) - 1;
    BTNode *root = EXPR();
    print(root);
    freeTree(root);

    return 0;
}


/* print a tree by pre-order. */
void print(BTNode *root){
    if (root->left) print(root->left);
    printf("%c", root->data);
    if (root->right) {
        if (root->right->data == '|' || root->right->data == '&') printf("(");
        print(root->right);
        if (root->right->data == '|' || root->right->data == '&') printf(")");
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

BTNode* EXPR(){
    BTNode *right_node = FACTOR();
    if(pos == -1 || expr[pos] == '('){
        return right_node;
    }

    BTNode *root = makeNode(expr[pos--]);
    root->right = right_node;
    root->left = EXPR();
    return root;
}

BTNode* FACTOR(){
    char c = expr[pos--];
    BTNode *node;
    switch(c){
        case ')':
            node = EXPR();
            pos--;
            return node;
        default:
            node = makeNode(c);
            return node;
    }
}

BTNode* makeNode(char c){
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    for(int i = 0; i < 6; i++){
        if(sym[i] == c){
            node->data = sym[i];
            break;
        }
    }
    if(c == 'A' || c == 'B' || c == 'C' || c == 'D'){
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

