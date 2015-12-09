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
input=2->4->6->8->10
res=10->8->6->4->2

input=2
res=2

input=NULL
res=Invalid input
*/
void reverse(struct node** head);
void reverse2(struct node** head);

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
		reverse(&head);
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


void reverse2(struct node** head){
	static struct node* prev;
	struct node* curr = *head;
	struct node* next = NULL;
	static int i;
	if (i == 0)
		prev = NULL;
	i++;
	if (curr == NULL){
		return;
	}
	else{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		reverse2(&next);
	}
	*head = prev;
	return;
}