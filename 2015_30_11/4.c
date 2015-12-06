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
arr={2,4,6,8,10}
res={10,8,6,4,2}

arr={2}
res={2}

arr=NULL
res=NULL
*/
void reverse(struct node** head);

int main(){
	int arr[] = { 2, 4, 6, 8, 10 };
	int len = 5;
	struct node* head = NULL;
	for (int i = 0; i<len; i++)
		add(&head, arr[i]);
	reverse(&head);
	while (head != NULL){
		printf("\n%d", head->num);
		head = head->next;
	}
	_getch();
	return 0;
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