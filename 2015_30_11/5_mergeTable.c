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
n1=3 n2=5 r=5
res=12

n1=3 n2=6 r=5
res=18

n1=1 n2=1 r=6
res=7

n1=3 n2=5 r=0
res=Invalid input

n1=2 n2=4 n3=6 n4=8 r=10
res=22

n1=2 n2=3 n3=5 n4=7 r=6
res=8
*/
int compute(int n1, int n2, int n3);
struct node* merge(struct node *head1, struct node* head2);
int compute2(int n1, int n2, int n3, int n4, int r);

int main(){
	int n1, n2, r,sel;
	printf("\nEnter number of n values(2 or 4):");
	scanf("%d", &sel);
	if (sel == 2 || sel == 4){
		printf("\nEnter value of n1 :");
		scanf("%d", &n1);
		printf("\nEnter value of n2 :");
		scanf("%d", &n2);
		if (sel == 2){
			printf("\nEnter value of r :");
			scanf("%d", &r);
			if (r > 0 && n2 > 0 && n1 > 0){
				int res = compute(n1, n2, r);
				printf("\nresult=%d", res);
			}
			else
				printf("\nInvalid input");
		}
		else{
			int n3, n4;
			printf("\nEnter value of n3 :");
			scanf("%d", &n3);
			printf("\nEnter value of n4 :");
			scanf("%d", &n4);
			printf("\nEnter value of r :");
			scanf("%d", &r);
			if (r > 0 && n2 > 0 && n1 > 0 && n3>0 && n4>0){
				int res = compute2(n1, n2,n3,n4, r);
				printf("\nresult=%d", res);
			}
			else
				printf("\nInvalid input");
		}
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

int compute(int n1, int n2, int r){
	if (n1 == 1 || n2 == 1)
		return r+1;
	if (n1%n2 == 0 || n2%n1==0){
		if (n2 < n1)
			n1 = n2;
	}
	struct node* head1 = NULL;
	for (int i = 1; i <= r+1; i++)
		add(&head1, n1*i);
	if (n1 %n2 != 0){
		struct node* head2 = NULL;
		for (int i = 1; i <= r+1; i++)
			add(&head2, n2*i);
		head1 = merge(head1, head2);
	}
	for (int i = 2; i <= r; i++)
		head1 = head1->next;
	return head1->next->num;

}

int compute2(int n1, int n2, int n3, int n4, int r){
	if (n1 == 1 || n2 == 1 || n3 == 1 || n4 == 1)
		return r+1;
	if (n1%n2 == 0 || n2%n1 == 0){
		if (n2 < n1)
			n1 = n2;
		n2 = 0;
	}
	if (n1%n3 == 0 || n3%n1 == 0){
		if (n3 < n1)
			n1 = n3;
		n3 = 0;
	}
	if (n1%n4 == 0 || n4%n1 == 0){
		if (n4 < n1)
			n1 = n4;
		n4 = 0;
	}
	if (n2!=0 && n3!=0 && (n2%n3 == 0 || n3%n2 == 0)){
		if (n3 < n2)
			n2 = n3;
		n3 = 0;
	}
	if (n2!=0 && n4!=0 && (n2%n4 == 0 || n4%n2 == 0)){
		if (n4 < n2)
			n2 = n4;
		n4 = 0;
	}
	if (n3 != 0 && n4 != 0 && (n3%n4 == 0 || n4%n3 == 0)){
		if (n4 < n3)
			n3 = n4;
		n4 = 0;
	}
	struct node* head1 = NULL;
	for (int i = 1; i <= r+1; i++)
		add(&head1, n1*i);
	if (n2 != 0){
	struct node* head2 = NULL;
	for (int i = 1; i <= r+1; i++)
		add(&head2, n2*i);
		head1 = merge(head1, head2);
	}
	if (n3 != 0){
		struct node* head2 = NULL;
		for (int i = 1; i <= r+1; i++)
			add(&head2, n3*i);
		head1 = merge(head1, head2);
	}
	if (n4 != 0){
		struct node* head2 = NULL;
		for (int i = 1; i <= r+1; i++)
			add(&head2, n4*i);
		head1 = merge(head1, head2);
	}
	for (int i = 2; i <= r; i++)
		head1 = head1->next;
	return head1->next->num;
}
