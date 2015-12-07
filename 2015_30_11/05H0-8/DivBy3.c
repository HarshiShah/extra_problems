#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>

/*TEST CASES
num=369		count=6		res=1
num=124		count=8		res=0
num=1111	count=6		res=1
num=3753	count=7		res=1
num=0		count=10	res=1
num=431		count=5		res=0*/
int validate1(char* num, int count);
int checkDiv1(int* num);
int validate2(char* num, int count);

int main(){
	char num[10000];
	int count;
	int res;
	printf("\nEnter number:");
	scanf("%s", num);
	printf("\nEnter count1");
	scanf("%d", &count);
	res = validate1(num, count);
	if (res == 1)
		printf("\ndivisible by 3");
	else
		printf("\nNot divisible by 3");
	_getch();
	return 0;
}

//the following function generates the required array Q and sends it to either checkDiv1()
int validate1(char* num, int count){
	int length = 0, j = 0, number[10000], i, flag = 0;
	for (i = 0; num[i] != '\0'; i++)
		length++;
	for (i = 0; i <length*count; i++){
		if (num[j] == '\0')
			j = 0;
		number[i] = num[j++] - '0';
	}
	number[i] = -1;
	return checkDiv1(number);
}


//the following function finds the sum of digits in array using recursion to check divisibility
int checkDiv1(int* num){
	int i = 0;
	unsigned int sum=0;
	int number[10000];
	while (num[i] != -1){
		sum += num[i++];
	}
	if (sum == 0||sum==3||sum==6||sum==9)
		return 1;
	else if (sum > 11){
		i = 0;
		//the following code converts the difference to a string and uses recursion
		while (sum != 0){
			number[i++] = (sum - (sum/10)*10);
			sum = sum / 10;
		}
		number[i] = -1;
		return checkDiv1(number);
	}
	else
		return 0;
}

//the following function directly computes the sum of digits in Q and checks divisibility without using recursion
int validate2(char* num, int count){
	int i,flag=0,odd=0,even=0,sum=0,sum1=0;
	for (i = 0; num[i] != '\0'; i++)
		sum = sum + (num[i] - '0');
	sum = sum*count;
	while (sum!=0){
		sum1 += sum - ((sum / 10) * 10);
		sum = sum / 10;
		if (sum == 0 && sum1 > 9){
			sum = sum1;
			sum1 = 0;
		}
	}
   if (sum1 == 0 || sum1 == 3 || sum1 == 6 || sum1 == 9)
		return 1;
	else
		return 0;

}
