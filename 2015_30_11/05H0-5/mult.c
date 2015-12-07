#include <stdio.h>
#include <conio.h>

int multiply(int num1, int num2);

int main(){
	int num1, num2,product;
	printf("\nEnter two numbers to be multiplied:");
	scanf_s("%d %d", &num1, &num2);
	product = multiply(num1, num2);
	printf("%d",product);
	_getch();
	return 0;
}

int multiply(int num1, int num2){
	int res = 0,flag=1;
	if (num2 < 0 && num1>0){
		num2 = add(~(num2),1);
		flag = -1;
	}
	else if (num2 < 0){
		num2 = add(~(num2), 1);
		num1 = add(~(num1), 1);
	}
	for (int i = 0; i < num2; i++){
		res =add(num1, res);
		}
	if (flag == -1)
		res = multiply(-1, res);
	return res;
}

int add(int num1, int num2){
	int carry;
	while (num2 != 0){
		carry = (num1&num2) << 1;
		num1 = num1^num2;
		num2 = carry;
	}
	return num1;
}