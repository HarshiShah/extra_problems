}#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

/*TEST CASES
num=36  res=1100100
num=5 res =101
num=73 res=1011001
num=7 res=11011
*/
int* baseMin2(unsigned int num,int* length);
int main(){
	unsigned int num;
	int length=0;
	printf("\nEnter number");
	scanf("%lu",&num);
	int* res = baseMin2(num,&length);
	for (int i = length-1; i>=0; i--)
		printf(" %d", res[i]);
	_getch();
	return 0;


//the following function returns an array containing base -2 equivalent of the number and length of the array
int* baseMin2(unsigned int num,int* length){
	int carry = 0,res[100],i=0;
	while (num != 0 || carry != 0){
		res[i] = (num % 2) + carry;
		carry = 0;
		//the following condition checks if the number exceeds 1
		if (res[i] > 1){
			res[i] = res[i] % 2;
			carry = 1;
		}
		//the following condition checks if 1 is generated at an odd position
		if (i % 2 ==1 && res[i] == 1)
			carry = 1;
		if (num != 0)
			num = num / 2;
		i++;
	}
	*length = i;
	return res;
}