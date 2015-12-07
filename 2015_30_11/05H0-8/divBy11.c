#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>

/*TEST CASES
num=121		res=1
num=111111111111	res=1
num=00000000000		res=1
num=0606060606		res=0
num=060506050605	res=1
*/
int checkDiv(char* num);
int checkDiv1(char* num);
int checkDiv2(char* num);
int main(){
	char num[10000];
	int res;
	printf("\nEnter number:");
	scanf("%s", num);
	res = checkDiv(num);
	if (res == 1)
		printf("\n%s is divisible by 11", num);
	else
		printf("\n%s is not divisible by 11", num);
	_getch();
	return 0;
}


//the following function finds the difference between sum of odd and even places and checks its divisibility using recursion
int checkDiv(char* num){
	int  odd = 0, even = 0, flag = 0, i = 0, diff;
	char number[4500];
	while (num[i] != '\0'){
		if (flag == 0){
			even += (num[i++] - '0');
			flag = 1;
		}
		else{
			odd += (num[i++] - '0');
			flag = 0;
		}
	}
	diff = even - odd;
	if (diff<0)
		diff = diff*-1;
	if (diff == 0)
		return 1;
	else if (diff > 10){
		i = 0;
		//the following code converts the difference to a string and uses recursion
		while (diff != 0){
			number[i++] = (diff - ((diff/10)*10))+'0';
			diff = diff / 10;
		}
		return checkDiv(number);
	}
	else
		return 0;
}

//In the following function the last digit is removed and subtracted from the remaining number repeatedly. However does not support very large strings
int checkDiv1(char* num){
	int i, temp, temp2;
	unsigned int number = 0;
	//convert string to number
	for (i = 0; num[i] != '\0'; i++){
		number = (number * 10) + (num[i] - '0');
	}
	//subtract last digit till a 1 digit number remains
	while (number > 9){
		temp2 = number / 10;
		temp = number - (temp2 * 10);//finds modulus
		number = temp2 - temp;
	}
	printf("\nHello1");
	if (number == 0)
		return 1;
	else
		return 0;
}

//the following method uses simple division to check whether the quotient is a float value or integer value
int checkDiv2(char* num){
	unsigned int number=0;
	printf("\nHELLO");
	for (int i = 0; num[i] != '\0'; i++){
		number = (number * 10) + (num[i] - '0');
	}
	float f = number / 11.0;
	int i = number / 11;
	printf("\n %f %d", f, i);
	if (f == i)
		return 1;
	else
		return 0;
}
