#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    int killed;
    struct _Node *next;
} Node;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, K;
        scanf("%d %d", &N, &K);
        Node* person = (Node*)malloc(sizeof(Node) * (N + 1));

        for(int i = 1; i <= N; i++){
            person[i].data = i;
            person[i].killed = 0;
            person[i].next = i != N ? &person[i + 1] : NULL; 
        }

        for(int i = 0; i < K; i++){
            int idx = 0;
            scanf("%d", &idx);
            if(person[idx].killed != 1 && person[idx].next != NULL){
                printf("%d\n", person[idx].next->data);
                person[idx].next->killed = 1;
                person[idx].next = person[idx].next->next;

            }
            else{
                printf("Penguin07 QQ\n");
            }
        }
    }

}