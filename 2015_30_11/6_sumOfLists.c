#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
#include <malloc.h> 

struct node {
	int num;
	struct node *next;
	struct node* prev;
};

struct node * createNode(int num, struct node* temp) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	newNode->prev = temp;
	return newNode;
}

void add(struct node **head, int num){
	struct node *temp = *head;
	if (*head == NULL){
		(*head) = createNode(num, NULL);
		(*head)->next = NULL;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(num, temp);
		temp->next->next = NULL;
	}
}

/*
list1=2->4->6->8
list2=2->4->6->8
res=4->9->3->6

list1=2
list2=2->4
res=4->4

list1=2->4
list2=2
res=4->4

list1=2->8->2->8->9->7
list2=8->2->7->3->4->1->6->8
res=1->1->1->0->2->3->8->6->8

list1=9->9->9
list2=9->9->9
res=1->9->9->8
*/
struct node* sum(struct node *head1, struct node* head2);

int main(){
	int num, len1, len2;
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
	if (len1 < 0 || len2 < 0)
		printf("\nInvalid input");
	else
		head1 = sum(head1, head2);
	while (head1 != NULL){
		printf("\n%d", head1->num);
		head1 = head1->next;
	}
	_getch();
	return 0;
}

struct node* sum(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* temp = head1;
	temp->num += head2->num;
	head2 = head2->next;
	//Increase list length incase of overflow
	if (temp->num > 9){
		struct node* temp2 = createNode(1, NULL);
		head1->prev = temp2;
		temp2->next = head1;
		head1 = head1->prev;
		temp->num = temp->num % 10;
	}
	while (temp->next != NULL && head2 != NULL){
		temp->next->num += head2->num;
		if (temp->next->num > 9){
			//Increase previous values incase of a carry
			if (temp->num < 9)
				temp->num = temp->num + 1;
			else{
				struct node* temp2 = temp;
				while (temp2->num == 9){
					temp2->num = 0;
					temp2 = temp2->prev;
				}
				temp2->num = temp2->num + 1;
			}
			temp->next->num = temp->next->num % 10;
		}
		temp = temp->next;
		head2 = head2->next;
	}
	//append incase of unequal lengths
	if (temp->next == NULL)
		temp->next = head2;
	return head1;
}