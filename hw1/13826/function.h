typedef struct _Node {
    int serial, stu_id;
    char name[1001]; 
    struct _Node* next;
} Node;

void eFormSort(Node *head);
