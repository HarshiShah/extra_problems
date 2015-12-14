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
res=2->6

list1=2->4
list2=2
res=2->6

list1=2->8->2->8->9->7
list2=8->2->7->3->4->1->6->8
res=8->3->0->1->7->0->6->5

list1=9->9->9
list2=9->9->9
res=1->9->9->8
*/
struct node* sum(struct node *head1, struct node* head2);
struct node* sum2(struct node *head1, struct node* head2);
void reverse(struct node** head);

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
		head1 = sum2(head1, head2);
	while (head1 != NULL){
		printf("\n%d", head1->num);
		head1 = head1->next;
	}
	_getch();
	return 0;
}

//This function works with a double linked list
struct node* sum(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node* temp1 = head1;
	struct node* temp2 = head2;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	int sum, carry = 0;
	while (temp1->prev != NULL && temp2->prev != NULL){
		sum = temp1->num + temp2->num + carry;
		temp1->num = sum % 10;
		carry = sum / 10;
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	sum = temp1->num + temp2->num + carry;
	temp1->num = sum % 10;
	carry = sum / 10;
	if (temp1->prev == NULL && temp2->prev!=NULL){
		temp1->prev = temp2->prev;
		temp2 = temp2->prev;
		temp2->next = temp1;
	}
	while (carry > 0){
		if (temp1->prev == NULL){
			struct node* new = createNode(carry, NULL);
			temp1->prev = new;
			new->next = temp1;
			carry = 0;
		}
		else{
			sum = temp1->prev->num + carry;
			temp1->prev->num = sum % 10;
			carry = sum / 10;
			temp1 = temp1->prev;
		}
	}
	while (temp1->prev != NULL)
		temp1 = temp1->prev;
	return temp1;
}

//This function works with a single linked list and uses list reverse function
struct node* sum2(struct node *head1, struct node* head2){
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	reverse(&head1);
	reverse(&head2);
	int carry = 0,sum;
	struct node* temp1 = head1;
	struct node* temp2 = head2;
	while (1){
		sum = temp1->num + temp2->num +carry;
		temp1->num = sum%10;
		carry = sum / 10;
		if (temp1->next != NULL && temp2->next != NULL){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			break;
	}
	if (temp1->next == NULL)
		temp1->next = temp2->next;
	while(carry > 0){
		if (temp1->next == NULL){
			temp1->next = createNode(carry, temp1);
			carry = 0;
		}
		else{
			sum = temp1->next->num + carry;
			temp1->next->num = sum % 10;
			carry = sum / 10;
			temp1 = temp1->next;
		}
			
	}
	reverse(&head1);
	return head1;
	
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