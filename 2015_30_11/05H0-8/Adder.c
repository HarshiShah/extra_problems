#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>

/*TEST CASES
num1=8888	num2=8888	sum=17776
num1=9999	num2=99999	sum=109998
num1=2345	num2=98734	sum=101079
num1=000	num2=00000	sum=0
num1=3454	num2=3454	sum=6908
*/
unsigned int add1(char* num1,char* num2);
unsigned int add2(char* num1, char* num2);
int main(){
	char num1[100];
	char num2[100];
	unsigned int res;
	printf("\nEnter number1:");
	scanf("%s", num1);
	printf("\nEnter number2:");
	scanf("%s", num2);
	res = add1(num1, num2);
	printf("\nSum=%d", res);
	_getch();
	return 0;
}

unsigned int add1(char* num1, char* num2){
	int i, len1 = 0, len2 = 0, carry = 0, num[100];
	unsigned int sum = 0;
	for (i = 0; num1[i] != '\0'; i++)
		len1++;
	for (i = 0; num2[i] != '\0'; i++)
		len2++;
    //Initialize i to maximum possible length of sum of two arrays
	if (len1 > len2)
		i = len1;
	else
		i = len2;
	num[i+1] = -1;
	//Calculate sum till both arrays reach 0th position
	while (len1 !=0 || len2 != 0){
		if (len1 == 0)
			num1[len1] = 0+'0';
		else
			len1--;
		if (len2 == 0)
			num2[len2] = 0+'0';
		else
			len2--;
		sum = ((num1[len1] - '0') + (num2[len2] - '0') + carry);
		if (sum > 9){
			carry = 1;
			num[i] = sum % 10;
		}
		else{
			carry = 0;
			num[i] = sum;
		}
		i--;
	}
	num[0] = carry;
	sum = 0;
	//Convert string to integer
	for (int j = 0; num[j]!=-1; j++){
		sum = (sum * 10) + num[j];
	}
	return sum;
}

unsigned int add2(char* num1, char* num2){
	int i, len1 = 0, len2 = 0, temp=1;
	unsigned int sum = 0;
	for (i = 0; num1[i] != '\0'; i++)
		len1++;
	for (i = 0; num2[i] != '\0'; i++)
		len2++;
	int l1 = len1;
	//add zeros to beginning of num1 if len1<len2 
	if (len1 < len2){
		l1 = len1-1;
		num1[len2] = '\0';
		for (i = len2-1; i >= len2 - len1; i--)
			num1[i] = num1[l1--];
		for (i = 0; i < len2-len1; i++)
			num1[i] =0+'0';
		l1 = len2;
	}
	//add zeros to beginning of num2 if len2<len1
	else{
		int l1 = len2;
		for (i = len1; i >= len1 - len2; i--)
			num2[i] = num2[l1--];
		for (i = 0; i < len1 - len2; i++)
			num2[i] = 0;
		l1 = len1;
	}
	//add the two strings to get the sum
	for (i = l1-1; i >=0; i--){
		sum = sum + ((num1[i] - '0') + (num2[i] - '0'))*temp;
		temp = temp * 10;
	}
	return sum;
}