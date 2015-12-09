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
Single inputs
	list1=2
	list2=3
	res=2->3

	list1=3
	list2=2
	res=2->3

Null inputs
	list1=NULL
	list2=2->4->6->8->10
	res=2->4->6->8->10

	list1=2->4->6->8->10
	list2=NULL
	res=2->4->6->8->10

	list1=NULL
	list2=NULL
	res=NULL

Ascending inputs
	list1=2->4->6->8->10
	list2=1->3->5->7->9
	res=1->2->3->4->5->6->7->8->9->10

Descending inputs
	list1=10->8->7->5->2
	list2=9->6->4->3->1
	res=10->9->8->7->6->5->4->3->2->1

Ascending and Descending
	list1=1->3->5->7->9
	list2=10->8->6->4->2
	res=1->2->3->4->5->6->7->8->9->10

Repeated values
	list1=2->4->6->8->10
	list2=2->4->6->8->10
	res=2->2->4->4->6->6->8->8->10->10

	list1=2->2->2
	list2=2->2
	res=2->2->2->2->2
*/
struct node* merge(struct node* head1, struct node* head2);
struct node* asc(struct node *head1, struct node* head2);
struct node* des(struct node *head1, struct node* head2);
struct node* reverse(struct node* head);
int checkOrder(struct node* head);

int main(){
	int num,len1, len2;
	printf("\nEnter length1 :");
	scanf("%d", &len1);
	struct node* head1 = NULL;
	for (int i = 0; i < len1; i++){
		printf("\nEnter node %d : ", i + 1);
		scanf("%d", &num);
		add(&head1, num);
	}
	printf("\nEnter length2 :");
	scanf("%d", &len2);
	struct node* head2 = NULL;
	for (int i = 0; i < len2; i++){
		printf("\nEnter node %d : ", i + 1);
		scanf("%d", &num);
		add(&head2, num);
	}
	head1 = merge(head1, head2);
	if (head1 == NULL)
		printf("\nNULL");
	while (head1 != NULL){
		printf("\n%d", head1->num);
		head1 = head1->next;
	}
	_getch();
	return 0;
}

//This function calls asc() or des() based on order of inputs and returns final list
struct node* merge(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if ((head1->next==NULL && head2->next==NULL))
		return asc(head1, head2);
	else if (head1->next == NULL){
		int order = checkOrder(head1);
		if (order == 0)
			return asc(head1, head2);
		else
			return des(head1, head2);
	}
	else if (head2->next == NULL){
		int order = checkOrder(head1);
		if (order==0)
			return asc(head1, head2);
		else
			return des(head1, head2);
	}
	else {
		int order1 = checkOrder(head1);
		int order2 = checkOrder(head2);
		if (order1==0 && order2==0)
			return asc(head1, head2);
		else if (order1 == 1 && order2 == 1)
			return des(head1, head2);
		else{
			if (order1 == 1)
				head1 = reverse(head1);
			else
				head2 = reverse(head2);
			asc(head1, head2);
		}
	}
}

//Merges two lists in ascending order
struct node* asc(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* final = NULL;
	if (head1->num <= head2->num){
		final = head1;
		final->next = asc(head1->next, head2);
	}
	else{
		final = head2;
		final->next = asc(head1, head2->next);
	}
	return final;
}

//Merges two lists in descending order
struct node* des(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* final = NULL;
	if (head1->num >= head2->num){
		final = head1;
		final->next = des(head1->next, head2);
	}
	else{
		final = head2;
		final->next = des(head1, head2->next);
	}
	return final;
}

//This function is called only in case of both ascending and descending input  
struct node* reverse(struct node* head){
	struct node* prev = NULL;
	struct node* curr = head;
	struct node* next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

//Returns 1 if a list is in descending order otherwise 0
int checkOrder(struct node* head){
	struct node* temp = head;
	while (temp->next!=NULL && temp->num == temp->next->num)
		temp = temp->next;
	if (temp->next != NULL && temp->num > temp->next->num)
		return 1;
	else
		return 0;
}