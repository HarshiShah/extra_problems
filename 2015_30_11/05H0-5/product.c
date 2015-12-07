#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mul1(int* arr, int length,int* res);
void mul2(int* arr, int length,int* res);
void mul3(int* arr, int length,int* res);

int main(){
	int arr[100],res[100];
	int length;
	printf("\nEnter array size");
	scanf_s("%d", &length);
	printf("\nEnter array elements:");
	for (int i = 0; i < length; i++)
			scanf_s("%d", &arr[i]);
	if (length > 2){
		mul3(arr, length,res);
		for (int i = 0; i < length; i++)
			printf(" %d", res[i]);
	}
	_getch();
	return 0;
}

void mul1(int* arr, int length,int* res){
	int multiple=1,flag=0,cnt=0;
	for (int i = 0; i < length; i++){
		if (arr[i] != 0)
			multiple *= arr[i];
		else{
			flag = 1;
			cnt++;
		}
	}
	if (cnt>1){
		for (int i = 0; i < length; i++)
			res[i] = 0;
	}
	else{
		for (int i = 0; i < length; i++){
			if (arr[i] != 0){
				if (flag == 0)
					res[i] = multiple / arr[i];
				else
					res[i] = 0;
			}
			else
				res[i] = multiple;
		}
	}
    }

void mul2(int* arr, int length,int* res){
	for (int i = 0; i < length; i++){
		int mul = 1;
		for (int j = 0; j < length; j++){
			if (i != j)
				mul *= arr[j];
		}
		res[i] = mul;
	}
}

void mul3(int* arr, int length,int* res){
	int prod = arr[0];
	res[length - 1] = arr[length - 1];
	for (int i = length - 2; i > 0; i--){
		res[i] = arr[i] * res[i + 1];
	}
	res[0] = res[1];
	for (int i = 1; i < length-1; i++){
		res[i] = res[i + 1] * prod;
		prod = prod*arr[i];
     }
	res[length - 1] = prod;
	}