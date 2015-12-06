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

void add(struct node **head, int num){
	struct node *temp = *head;
	if (*head == NULL){
		(*head) = createNode(num);
		(*head)->next = NULL;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(num);
		temp->next->next = NULL;
	}
}

/*
arr={1,2,3,15,10,4}
res=1--2--3--4--10--15

arr={5,3}
res=3--5

*/
void  sortList(struct node *head);

int main(){
	int arr[] = { 15, 5, 7, 9, 4, 18, 20 };
	int len = 7;
	struct node* head = NULL;
	for (int i = 0; i<len; i++)
		add(&head, arr[i]);
	sortList(head);
	while (head != NULL){
		printf("\n%d", head->num);
		head = head->next;
	}
	_getch();
	return 0;
}

void  sortList(struct node *head){
	struct node* first = head;
	struct node* sec = head->next;
	if (first == NULL || sec == NULL)
		return;
	if (sec->next != NULL){
		while (first->num < first->next->num){
			first = first->next;
		}
		sec = first->next;
		while (sec->num < sec->next->num){
			sec = sec->next;
		}
		sec = sec->next;
	}
	int temp = first->num;
	first->num = sec->num;
	sec->num = temp;
	return;
}