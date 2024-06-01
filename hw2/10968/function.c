#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"


void printInfix(Node *root){
     if (root->left) printInfix(root->left);
    printf("%c", root->data);
    if (root->right) {
        if (root->right->data == '|' || root->right->data == '&') printf("(");
        printInfix(root->right);
        if (root->right->data == '|' || root->right->data == '&') printf(")");
    }
}