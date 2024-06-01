#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define mod 998244353 // Define a modulo for the beauty calculation.

// Define a node structure for the expression tree.
typedef struct _Node {
    int val; // {0 ~ 9: number, -1: +, -2: -, -3: *}
    int ans;
    struct _Node *lc, *rc; // Left child, right child.
} Node;

int n;
int pos, now_pos = 0;
char s[505] = {}; // Input string representing the preorder expression of the tree.
Node *arr[505] = {}; // Array to store pointers to nodes for easy access.
// Function to build the expression tree from the input string.

Node* build();
int eval(Node *r);
bool dfs(Node *now, Node *target);
bool check(int a, int b);
void swap(int a, int b);
int value(char c);


int main() {

    scanf("%d", &n);
    scanf("%s", s); // Read the input string.
    Node *root = build();
    
    // eval(root);

    
    // printf("root val : %d\n", root->val);
    // printf("n : %d\n", n);


    int max_beauty = eval(root);
    //printf("max_beauty : %d\n", max_beauty);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!check(i, j)) {
                swap(i, j);
                // printf("i: %d, j: %d\n", i, j);
                // printf("%d\n",  eval(root));
                int ans = eval(root);
                max_beauty = (ans > max_beauty) ? ans : max_beauty;
                swap(i, j); // Swap back for next iteration
            }
        }
    }

    printf("%d\n", max_beauty);
}
 
Node *build() {
    if (now_pos >= n) return NULL;
    Node *root = (Node*)malloc(sizeof(Node));
    root->val = value(s[now_pos]);
    root->lc = root->rc = NULL;
    arr[now_pos++] = root;
    if(root->val < 0){
        root->lc = build();
        root->rc = build();
    }
    
    
    return root;

}

// Function to evaluate the expression tree and calculate its beauty.
int eval(Node *r) {
    // if (r->lc == NULL && r->rc == NULL) return r->val;

    // // printf("%d %d\n", r->lc->val, r->rc->val);
    // int a = eval(r->lc) % mod;
    // //printf("a: %d\n", a);
    // int b = eval(r->rc) % mod;


    // if (r->val == -1) r->ans = (a + b) % mod;
    // else if (r->val == -2) r->ans = (a - b + mod) % mod;
    // else if (r->val == -3) r->ans = (1ll * a * b) % mod;

    // return r->ans;

    

    if(r->val >= 0) return r->val;
    int lv = eval(r->lc);
    int rv = eval(r->rc);
    if(r->val == -1) return (1ll * lv + rv) % mod;
    if(r->val == -2) return (1ll * lv - rv + mod) % mod;
    if(r->val == -3) return (1ll * lv * rv) % mod;
    return 0;
}

// Depth-First Search function to check if target node is in the subtree rooted at 'now'.
bool dfs(Node *now, Node *target) {
    
    if(now == NULL) return false; 
    if(now == target) { 
        return true;
    }
    else { 
        return dfs(now->lc, target) || dfs(now->rc, target);
    }
}

// Function to check if two nodes have an ancestor-descendant relationship.
bool check(int a, int b) {
    return dfs(arr[a], arr[b]) || dfs(arr[b], arr[a]);
}

// Function to swap the subtrees rooted at nodes a and b.
void swap(int a, int b) {
    Node* tmp = arr[a]->lc;
    arr[a]->lc = arr[b]->lc;
    arr[b]->lc = tmp;

    tmp = arr[a]->rc;
    arr[a]->rc = arr[b]->rc;
    arr[b]->rc = tmp;

    int tmp2 = arr[a]->val;
    arr[a]->val = arr[b]->val;
    arr[b]->val = tmp2;

}

int value(char c){
    if(c == '+') return -1;
    if(c == '-') return -2;
    if(c == '*') return -3;
    return c - '0';

}

// Main function.
