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
arr1={2,4,6,8,10}
arr2={2,4,6,8,10}
res=4--8--12--16--20

arr1={2}
arr2={2,4}
res=4--4

arr1={2,4}
arr2={2}
res=4--4
*/
struct node*  sum(struct node *head1, struct node* head2);

int main(){
	int arr1[] = { 2, 4, 6, 8 };
	int arr2[] = { 2, 4, 6, 8, 12, 16 };
	int len1 = 4;
	int len2 = 6;
	struct node* head1 = NULL;
	for (int i = 0; i<len1; i++)
		add(&head1, arr1[i]);
	struct node* head2 = NULL;
	for (int i = 0; i<len2; i++)
		add(&head2, arr2[i]);
	head1 = sum(head1, head2);
	while (head1 != NULL){
		printf("\n%d", head1->num);
		head1 = head1->next;
	}
	_getch();
	return 0;
}

struct node*  sum(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* temp = head1;
	temp->num += head2->num;
	head2 = head2->next;
	while (temp->next != NULL && head2 != NULL){
		temp->next->num += head2->num;
		temp = temp->next;
		head2 = head2->next;
	}
	if (temp->next == NULL)
		temp->next = head2;
	return head1;
}