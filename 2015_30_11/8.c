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
arr={1,2,7,20,15,10}r
res={1,2,7,10,15,20}

arr={2,4}
res={2,4}

arr={2}
arr={2}

arr={1,2,4,5,7}
res={1,2,4,5,7}
*/
void  arrangeList(struct node *head);
void reverse(struct node** head);

int main(){
	int arr[] = { 2 };
	int len = 1;
	struct node* head = NULL;
	for (int i = 0; i<len; i++)
		add(&head, arr[i]);
	arrangeList(head);
	while (head != NULL){
		printf("\n%d", head->num);
		head = head->next;
	}
	printf("\nEXIT");
	_getch();
	return 0;
}

void arrangeList(struct node *head){
	if (head == NULL || head->next == NULL)
		return;
	struct node* temp = head;
	while (temp->next != NULL && temp->next->next != NULL && temp->next->num < temp->next->next->num)
		temp = temp->next;
	reverse(&temp->next);
	return;
}

void reverse(struct node** head){
	struct node* part1;
	struct node* part2;
	if (*head == NULL)
		return;
	part1 = *head;
	part2 = part1->next;
	if (part2 == NULL)
		return;
	reverse(&part2);
	part1->next->next = part1;
	part1->next = NULL;
	*head = part2;
}