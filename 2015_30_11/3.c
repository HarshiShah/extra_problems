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

void add_circular(struct node**head,struct node** tail, struct node* element);
int main(){
	int arr[] = { 2,4,5,6,8};
	int len = 5;
	struct node* head = NULL;
	struct mode* tail = NULL;
	for (int i = 0; i < len; i++)
		add_circular(&head,&tail, createNode(arr[i]));
	struct node* temp = head;
	printf("\n%d", head->num);
	temp = temp->next;
	while (temp != head){
		printf("\n%d", temp->num);
		temp = temp->next;
	}
	_getch();
	return 0;
}

void add_circular(struct node**head,struct node** tail, struct node* element){
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