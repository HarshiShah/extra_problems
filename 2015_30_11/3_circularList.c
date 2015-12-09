#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
#include <malloc.h> 

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

void add_circular(struct node**head, struct node** tail, struct node* element);
int main(){
	int num, len;
	struct node* head = NULL;
	struct mode* tail = NULL;
	printf("\nEnter length :");
	scanf("%d", &len);
	if (len > 0){
		for (int i = 0; i < len; i++){
			printf("\nEnter node : ", i + 1);
			scanf("%d", &num);
			add_circular(&head, &tail, createNode(num));
		}
		struct node* temp = head;
		printf("\nList elements=\n%d", head->num);
		temp = temp->next;
		while (temp != head){
			printf("\n%d", temp->num);
			temp = temp->next;
		}
	}
	else
		printf("\nlist=NULL");
	_getch();
	return 0;
}

void add_circular(struct node**head, struct node** tail, struct node* element){
	struct node* temp = *tail;
	struct node* temp2 = *head;
	if (temp2 == NULL){
		element->next = element;
		*head = element;
		*tail = element;
	}
	else{
		temp->next = element;
		element->next = *head;
		*head = element;
	}
	return;
}

