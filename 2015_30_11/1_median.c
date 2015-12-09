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
input=NULL
Invalid input

input=2
median=2.0

input=2->4
median=3.0

input=2->4->6->8->10
median=6.0

input=2->4->6->8->10->12}
median=7.0

input=1->2->3->4->5->6
median=3.5

input=-1->-2->-3->-4->-5->-6
median=-3.5
*/
float median(struct node *head);

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
		float res = median(head);
		printf("\nMedian=%.01f", res);
	}
	else
		printf("\nInvalid input");
		_getch();
	return 0;
}

float median(struct node *head){
	if (head->next == NULL)
		return head->num;
	struct node* temp = head;
	struct node* last = head;
	while (last->next != NULL && last->next->next != NULL){
		last = last->next->next;
		temp = temp->next;
	}
	if (last->next == NULL) //In case of odd length
		return temp->num/1.0;
	else   //Even length
		return (temp->num + temp->next->num) / 2.0;
}
