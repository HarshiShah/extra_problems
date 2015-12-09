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
n1=3 n2=5 n3=8
res=24

n1=3 n2=6 n3=5
res=24

n1=1 n2=1 n3=6
res=6

n1=3 n2=5 n3=0
res=Invalid input
*/
int compute(int n1, int n2, int n3);
struct node* merge(struct node *head1, struct node* head2);

int main(){
	int n1, n2, n3;
	printf("\nEnter value of n1");
	scanf("%d", &n1);
	printf("\nEnter value of n2");
	scanf("%d", &n2);
	printf("\nEnter value of n3");
	scanf("%d", &n3);
	if (n3 > 0 && n2>0 && n1>0){
		int res = compute(n1, n2, n3);
		printf("\nresult=%d", res);
	}
	else
	printf("\nInvalid input");
	_getch();
	return 0;
}

struct node* merge(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* final;
	if (head1->num < head2->num){
		final = head1;
		final->next = merge(head1->next, head2);
	}
	else if (head1->num > head2->num){
		final = head2;
		final->next = merge(head1, head2->next);
	}
	else{
		final = head1;
		final->next = merge(head1->next, head2->next);
	}
	return final;
}

int compute(int n1, int n2, int n3){
	if (n1%n2 == 0){
		if (n2 < n1)
			n1 = n2;
	}
	struct node* head1 = NULL;
	for (int i = 1; i <= n3; i++)
		add(&head1, n1*i);
	if (n1 %n2 != 0){
		struct node* head2 = NULL;
		for (int i = 1; i <= n3; i++)
			add(&head2, n2*i);
		head1 = merge(head1, head2);
	}
	for (int i = 2; i <= n3; i++)
		head1 = head1->next;
	return head1->num;

}
