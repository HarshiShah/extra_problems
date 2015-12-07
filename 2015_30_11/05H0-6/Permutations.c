#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void sort(int* arr, int start, int end);
void swap(int* a, int* b);
int* permute(unsigned int num);
int compute(int* arr, int left, int right, int* arr1);

int main(){
	unsigned int num;
	int* res;
	printf("\nEnter number");
	scanf_s("%lu", &num);
	res = permute(num);
	printf("\n\nThe possible permutations are\n");
	for (int i = 0; res[i] != -1; i++)
		printf(" \n%d", res[i]);
	_getch();
	return 0;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

//the following method sorts the input array
void sort(int* arr, int start, int end){
	if (end > start + 1){
		int piv = arr[start], left = start + 1, right = end;
		while (left < right){
			if (arr[left] <= piv)
				left++;
			else
				swap(&arr[left], &arr[--right]);
		}
		swap(&arr[--left], &arr[start]);
		sort(arr, start, left);
		sort(arr, right, end);
	}
}

//the following method generates all permutations
int* permute(unsigned int num){
	int arr[10], i = 0, count = 0, res = 0, dup = 0;
	unsigned int arr1[100000] = { 0 };
	unsigned int num1 = num;
	while (num1 != 0){
		arr[i++] = num1 % 10;
		num1 = num1 / 10;
	}
	count = compute(arr, 0, i - 1, arr1);
	printf("\ncount=%d", count);
	sort(arr1, 0, count);
	arr1[count] = -1;
	return arr1;
}


int compute(int* arr, int left, int right, int* arr1){
	static int num;
	if (left == right){
		int pow = 1, j;
		for (j = 0; j <= right; j++)
			pow = pow * 10;
		j = 0;
		pow = pow / 10;
		while (pow > 0){
			arr1[num] += (arr[j++] % 10)*pow;
			pow = pow / 10;
		}
		num++;
	}
	else{
		for (int i = left; i <= right; i++){
			swap(&arr[left], &arr[i]);
			compute(arr, left + 1, right, arr1);
			swap(&arr[left], &arr[i]);
		}
	}
	return num;
}