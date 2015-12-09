#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void generate1(int num, int* res);
void generate2(int num, int* res);


int main(){
	int res[100], num;
	printf("\nEnter number");
	scanf("%d", &num);
	generate1(num, res);
	for (int i = 0; res[i] != -1; i++)
		printf("%d", res[i]);
	_getch();
	return 0;

}

void generate1(int num, int* res){
	int sum = 2, num1 = 1, num2 = 1, diff, temp, cnt = 1;
	res[0] = 1;
	res[1] = 1;
	if (num == 1){
		res[1] = -1;
		return;
	}
	while (sum < num){
		temp = num1 + num2;
		sum += temp;
		num1 = num2;
		num2 = temp;
		res[++cnt] = 1;
	}
	diff = sum - num;
	res[cnt + 1] = -1;
	while (diff>0){
		cnt--;
		if (num1 <= diff){
			res[cnt] = 0;
			diff = diff - num1;
		}
		temp = num2 - num1;
		num2 = num1;
		num1 = temp;
	}
}


void generate2(int num, int* res){
	int sum = 2, num1 = 1, num2 = 1, diff, temp, cnt = 1;
	printf("\n--------------\n");
	while (sum < num){
		temp = num1 + num2;
		sum += temp;
		num1 = num2;
		num2 = temp;
		cnt++;
	}
	printf("\n cnt=%d", cnt);
	res[cnt] = 1;
	num = num-num2;
	printf("\nnum=%d sum=%d", num,sum);
	res[cnt + 1] = -1;
	while (num>0){
		cnt--;
		sum = sum - num2;
		temp = num2 - num1;
		num2 = num1;
		num1 = temp;
		printf("\nnum=%d sum=%d num1=%d num2=%d\n", num, sum,num1,num2);
		if (num <= sum && num>(sum-num2)){
			res[cnt] = 1;
			num = num - num2;
		}
		else
			res[cnt] = 0;
		
	}
}