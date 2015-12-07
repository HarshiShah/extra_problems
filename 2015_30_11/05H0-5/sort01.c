#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void sort1(int* arr, int length);
void sort2(int* arr, int length);
void sort3(int* arr, int length);
void swap(int* a, int* b);
void sort4(int* arr, int length);

int main(){
	int arr[100];
	int length;
	printf("\nEnter array length");
	scanf_s("%d", &length);
	if (length > 0){
		printf("\nEnter array elements(0 or 1):");
		for (int i = 0; i < length; i++){
			scanf_s("%d", &arr[i]);
			if (arr[i] != 0 && arr[i] != 1){
				printf("\nInvalid input");
				_getch();
				return 0;
			}
		}
		sort1(arr, length);
		printf("\nThe sorted array is\n");
		for (int i = 0; i < length; i++)
			printf(" %d", arr[i]);
	}
	_getch();
	return 0;

}

void sort1(int* arr, int length){
	int cnt=0;
	for (int i = 0; i < length; i++){
		if (arr[i] == 0)
			cnt++;
	}
	for (int i = 0; i < length; i++){
		if (i < cnt)
			arr[i] = 0;
		else
			arr[i] = 1;
	}
}

void sort2(int* arr, int length){
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	for (int i = 0; i < length - sum; i++)
		arr[i] = 0;
	for (int i = length-sum; i < length; i++)
		arr[i] = 1;
	}

void sort3(int* arr, int length){
	int first = 0, i = 0;
	while (i < length-1){
		if (arr[i] == 0)
			swap(&arr[first++], &arr[i]);
		i++;
	}
}
void sort4(int* arr, int length){
	int temp;
	for (int i = 0; i < length-1; i++){
		for (int j = 0; j < length - i-1; j++){
			if (arr[j]>arr[j + 1]){
				swap(arr[j], arr[j + 1]);
		}

	}
	printf("\nsort4\n");
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}