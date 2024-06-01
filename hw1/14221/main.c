#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char val;
    struct _Node* next;
} Node;

// list[i]'s head node
Node *head[100005] = {};

// list[i]'s tail node
Node *tail[100005] = {};

// reverse(list[i])'s head node
Node *rev_head[100005] = {};

// reverse(list[i])'s tail node
Node *rev_tail[100005] = {};

/*
list[a] = 1 -> 2 -> 3 -> 4
rev_list[a] = 4 -> 3 -> 2 -> 1
head[a]->val = 1, tail[a]->val = 4
rev_head[a]->val = 4, rev_tail[a]->val = 1
you can use rev_head and rev_tail to get O(1) reverse
*/

void swap(int a, int b) {
    // swap list[a] and list[b]
    Node *tmp = head[a];
    head[a] = head[b];
    head[b] = tmp;

    tmp = tail[a];
    tail[a] = tail[b];
    tail[b] = tmp;

    tmp = rev_head[a];
    rev_head[a] = rev_head[b];
    rev_head[b] = tmp;

    tmp = rev_tail[a];
    rev_tail[a] = rev_tail[b];
    rev_tail[b] = tmp;
}

void append(int a, int b) {
    // append list[a] to list[b]'s behind
    if (head[a] == NULL) return;
    if (head[b] == NULL) {
        swap(a, b);
        return;
    }

    tail[b]->next = head[a];
    tail[b] = tail[a];

    head[a] = NULL;
    tail[a] = NULL;


    rev_tail[a]->next = rev_head[b];
    rev_head[b] = rev_head[a];
    rev_head[a] = NULL;
    rev_tail[a] = NULL;

}

void reverse(int a) {
    // reverse list[a]
    if (head[a] == NULL) return;

    Node *tmp = head[a];
    head[a] = rev_head[a];
    rev_head[a] = tmp;

    tmp = tail[a];
    tail[a] = rev_tail[a];
    rev_tail[a] = tmp;

    
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int sz;
        scanf("%d", &sz);

        if (sz > 0) {
            char c;
            scanf(" %c", &c);

            Node *node = (Node *)malloc(sizeof(Node));
            Node *rev_node = (Node *)malloc(sizeof(Node));
            node->val = c;
            node->next = NULL;

            rev_node->val = c;
            rev_node->next = NULL;

            head[i] = node;
            rev_tail[i] = rev_node;
            

            for (int j = 1; j < sz; j++) {
                scanf(" %c", &c);

                Node *new_node = (Node *)malloc(sizeof(Node));
                Node *new_rev_node = (Node *)malloc(sizeof(Node));

                new_node->val = c;
                new_node->next = NULL;

                new_rev_node->val = c;
                new_rev_node->next = NULL;

                node->next = new_node;
                node = new_node;

                Node *prev = rev_node;
                rev_node = new_rev_node;
                rev_node->next = prev;

            }
            
            tail[i] = node;
            rev_head[i] = rev_node;
        }
        else{
            continue;
        }
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int type, a, b;
        scanf("%d %d", &type, &a);

        if (type != 4) {
            scanf("%d", &b);
        }

        switch (type) {
            case 1:
                append(b, a);
                swap(a, b);
                break;
            case 2:
                append(a, b);
                break;
            case 3:
                swap(a, b);
                break;
            case 4:
                reverse(a);
                break;
            default:
                break;
        }
    }

    for (int i = 1; i <= N; i++) {
        Node *current = head[i];

        while (current != NULL) {
            printf("%c", current->val);
            current = current->next;

        }

        printf("\n");
    }

    return 0;
}