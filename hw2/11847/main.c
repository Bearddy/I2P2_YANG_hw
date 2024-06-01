#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);
int solve(Node *root, int n);

int main(void)
{
    int n;
   // the number of test cases


    Node *root=NULL;
    constructTree(&root);// construct syntax tree

    for (int i = 0; i < 16; i++)
    {
        printf("%d %d %d %d ", (i >> 3) & 1, (i >> 2) & 1, (i >> 1) & 1, i & 1);
        printf("%d\n", solve(root, i));
    }



    return 0;
}

int solve(Node *root, int n){
    if(root->data == '&'){
        return solve(root->left, n) & solve(root->right, n);
    }
    else if(root->data == '|'){
        return solve(root->left, n) | solve(root->right, n);
    }
    else{
        return (n >> (3- (root->data - 'A'))) & 1;
    }
}

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL)
    {
        (*head) = (Node *)malloc(sizeof(Node));
        c = getchar();

        (*head)->data = c;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}



void printInfix(Node *root){
    if (root->left) printInfix(root->left);
    printf("%c", root->data);
    if (root->right) {
        if (root->right->data == '|' || root->right->data == '&') printf("(");
        printInfix(root->right);
        if (root->right->data == '|' || root->right->data == '&') printf(")");
    }
}
