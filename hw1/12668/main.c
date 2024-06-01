#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
// Node struct used for doubly-linked lists.
typedef struct _Node {
	char chr;
	struct _Node* next;
	struct _Node* prev;
} Node;



int main() {
	int T;
	scanf("%d", &T);
	while (T--) {

		Node* head = (Node*)malloc(sizeof(Node));

		head->prev = NULL;
		head->next = NULL;

		Node* curNode = head;
		int N;
		scanf("%d\n", &N);
		while (N--) {
			char input = getchar();
			if(input == 'L'){
				if (curNode->prev != NULL) 
					curNode = curNode->prev;
			}
			else if(input == 'R'){
				if (curNode->next != NULL) 
					curNode = curNode->next;
			}
			else if(input == 'B'){
				if(curNode->prev != NULL){
					Node* temp = curNode;
					curNode->prev->next = curNode->next;
					if(curNode->next != NULL)
						curNode->next->prev = curNode->prev;
					curNode = curNode->prev;
					free(temp);
				}
			}
			else{
				Node* newNode = (Node*)malloc(sizeof(Node));
				newNode->chr = input;
				newNode->prev = curNode;
				newNode->next = curNode->next;
				if(curNode->next != NULL)
					curNode->next->prev = newNode;
				curNode->next = newNode;
				curNode = newNode;
			}
		}

		Node* print = head->next;
		while(print != NULL){
			printf("%c", print->chr);
			Node* temp = print;
			print = print->next;
			free(temp);
		}
		printf("\n");
		free(head);

	}

	return 0;
}


