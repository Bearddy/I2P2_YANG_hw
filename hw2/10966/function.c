#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

//typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;


// typedef struct _Node {
//     TokenSet data;
//     struct _Node *left, *right;
// } BTNode;

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
    switch(c){
        case 'A': 
            node->data = ID_A; 
            break;
        case 'B': 
            node->data = ID_B; 
            break;
        case 'C': 
            node->data = ID_C; 
            break;
        case 'D': 
            node->data = ID_D; 
            break;
        case '&': 
            node->data = OP_AND; 
            break;
        case '|': 
            node->data = OP_OR; 
            break;
    }

    if(c == 'A' || c == 'B' || c == 'C' || c == 'D'){
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}


