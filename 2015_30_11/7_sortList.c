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
input=15->2->3->10->1->40
res=1->2->3->10->15->40

input=2->2->6->4->2
res=2->2->2->4->6

input=5->3
res=3->5

input=2->2->2->2->2
res=2->2->2->2->2
*/
void sortList(struct node *head);

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
		sortList(head);
		printf("\nSorted list\n");
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

void sortList(struct node *head){
	struct node* first = head;
	struct node* sec = head->next;
	if (first == NULL || sec == NULL)
		return;
	if (sec->next != NULL){
		while (first->next!=NULL && first->num <= first->next->num){
			first = first->next;
		}
		if (first->next == NULL)
			return;
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
