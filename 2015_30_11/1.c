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
arr={2}
median=2

arr={2,4}
median=3

arr={2,4,6,8,10}
median=6

arr={2,4,6,8,10,12}
median=7
*/
int median(struct node **head1);

int main(){
	int arr[] = { 2, 4, 6, 8, 10,12 };
	int len = 6;
	struct node* head = NULL;
	for (int i = 0; i<len; i++)
		add(&head, arr[i]);
	int res=median(head);
	printf("\nMedian=%d",res);
	_getch();
	return 0;
}

int median(struct node *head){
	struct node* temp = head;
	if (temp == NULL)
		return -1;
	if (temp->next == NULL)
		return temp->num;
	int len = 0;
	while (temp != NULL){
		temp = temp->next;
		len++;
	}
	int i = 0;
	temp = head;
	while (i < (len-1)/2){
		temp = temp->next;
		i++;
	}
	if (len % 2 == 1)
		return temp->num;
	else
		return (temp->num + temp->next->num) / 2;
}