#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
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
void arrangeList(struct node *head);
void reverse(struct node** head);

int main(){
	int num, len;
	printf("\nEnter length :");
	scanf("%d", &len);
	if (len > 0){
		struct node* head = NULL;
		for (int i = 0; i < len; i++){
			printf("\nEnter node %d : ", i + 1);
			scanf("%d", &num);
			add(&head, num);
		}
		arrangeList(head);
		while (head != NULL){
			printf("\n%d", head->num);
			head = head->next;
		}
	}
	else
		printf("\nInvalid input");
	_getch();
	return 0;
}

//This function reverses the descending part and appends it to the ascending part
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
