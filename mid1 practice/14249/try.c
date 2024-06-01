#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define mod 998244353

// Define a node structure for the expression tree.
typedef struct _Node {
    int val; // {0 ~ 9: number, -1: +, -2: -, -3: *}
    int ans;
    struct _Node *lc, *rc; // Left child, right child.
} Node;

char s[505] = {}; // Input string representing the preorder expression of the tree.
Node *arr[505] = {}; // Array to store pointers to nodes for easy access.
int n;

// Function to build the expression tree from the input string.
Node *build(int *idx) {
    char c = s[*idx];
    *idx += 1;

    Node *node = (Node *)malloc(sizeof(Node));
    if (c >= '0' && c <= '9') {
        node->val = c - '0';
        node->lc = node->rc = NULL;
    } else {
        node->val = (c == '+') ? -1 : ((c == '-') ? -2 : -3);
        node->lc = build(idx);
        node->rc = build(idx);
    }
    return node;
}

// Function to evaluate the expression tree and calculate its beauty.
int eval(Node *r) {
    if (r->lc == NULL && r->rc == NULL)
        return r->val;

    int a = eval(r->lc) % mod;
    int b = eval(r->rc) % mod;

    if (r->val == -1)
        r->ans = (a + b) % mod;
    else if (r->val == -2)
        r->ans = (a - b + mod) % mod;
    else
        r->ans = (1LL * a * b) % mod;

    return r->ans;
}

// Depth-First Search function to check if target node is in the subtree rooted at 'now'.
bool dfs(Node *now, Node *target) {
    if (now == NULL)
        return false;
    if (now == target)
        return true;
    return dfs(now->lc, target) || dfs(now->rc, target);
}

// Function to check if two nodes have an ancestor-descendant relationship.
bool check(Node *a, Node *b) {
    return dfs(a, b) || dfs(b, a);
}

// Function to swap the subtrees rooted at nodes a and b.
void swap(Node *a, Node *b) {
    Node *tmp = a->lc;
    a->lc = b->lc;
    b->lc = tmp;

    tmp = a->rc;
    a->rc = b->rc;
    b->rc = tmp;
}

// Main function.
int main() {
    scanf("%d", &n);
    scanf("%s", s);

    int idx = 0;
    Node *root = build(&idx);

    eval(root);
    
    int beauty = root->ans;

    int max_beauty = beauty;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!check(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
                eval(root);
                max_beauty = (root->ans > max_beauty) ? root->ans : max_beauty;
                swap(arr[i], arr[j]); // Swap back for next iteration
            }
        }
    }

    printf("%d\n", max_beauty);
    
    return 0;
}
