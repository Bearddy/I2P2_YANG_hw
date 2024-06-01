#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} Node;

int preIdx = 0;
int inorder[200005], preorder[200005], pos[200005];

Node* make(int n){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int start, int end){
    if (start > end) return NULL;

    Node* root = make(preorder[preIdx++]);
 
    if (start == end) return root;

    int inIndex = pos[root->data];



    root->left = buildTree(start, inIndex - 1);
    root->right = buildTree(inIndex + 1, end);

    return root;
}

void printPostorder(Node *root){
    if (root == NULL)
        return;
    if(root->left) printPostorder(root->left);
    if(root->right) printPostorder(root->right);
    printf("%d ", root->data);
}


int main(){
    int m;
    scanf("%d", &m);
    for(int j = 0; j < m; j++){
        scanf("%d", &inorder[j]);
        pos[inorder[j]] = j;
    } 
    for(int j = 0; j < m; j++) scanf("%d", &preorder[j]);
    Node *root = buildTree(0, m - 1);
    printPostorder(root);
    printf("\n");
}
