#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>

/* TEST CASES
num1=00000 num2=00000 res=00000
num1=2314 num2=1234 res=3548
num1=12765  num2=08345 res=21110
num1=8929 num2=0000 res=8929
num1=9999 num2=9999 res=19998
*/
int* add1(char* num1, char* num2);
int main(){
	char num1[100];
	char num2[100];
	int* res;
	printf("\nEnter number1:");
	scanf("%s", num1);
	printf("\nEnter number2:");
	scanf("%s", num2);
	res = add1(num1, num2);
	printf("\nSum=");
	for (int i = 0; res[i] != -1; i++)
		printf(" %d", res[i]);
	_getch();
	return 0;
}

int* add1(char* num1, char* num2){
	int sum, i1, i2=0, res[100];
	for (i1 = 0; num1[i1] != '\0'; i1++){
		sum = ((num1[i1] - '0') + (num2[i1] - '0'));
		res[i1] = sum % 10;
		if (sum < 9)
			i2 = i1;
		else if (sum>9 && i1!=0){
			res[i2] = res[i2] + 1;
			i2++;
			while (i2 < i1){
				res[i2] = 0;
				i2++;
			}
		}
	}
	if ((num1[0]-'0') + (num2[0]-'0')>9){
		for (int i = i1; i >= 0; i--)
			res[i] = res[i - 1];
		res[0] = 1;
		i1++;
	}
	res[i1] = -1;
	return res;
}